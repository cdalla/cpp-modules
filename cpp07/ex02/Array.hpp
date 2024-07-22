#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
	
		size_t	_size;
		T	*_elements;
		
	public:
	
		Array<T>(void) : _size(0), _elements(nullptr)
		{	
			return ;
		}
		
		Array<T>(unsigned int n) : _size(n), _elements(new T[_size])
		{
			//_elements = new T[_size];

			return ;
		}
		
		~Array<T>(void)
		{
			delete [] _elements;
			
			return ;
		}
		
		Array<T>(Array<T> const & src)
		{
			this->_elements = nullptr;
			*this = src;
			
			return ;
		}
		
		Array<T> & operator=(Array const & src)
		{	
			if (this == &src)
				return *this;
			
			delete [] this->_elements;
			this->_size = src.size();
			this->_elements = new T[_size];
			
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_elements[i] = src._elements[i];
			}
			
			return *this;
		}
		
		T & operator[](const unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return this->_elements[index];
		}
		
		size_t size() const
		{
			return this->_size;
		}
		
};

#endif