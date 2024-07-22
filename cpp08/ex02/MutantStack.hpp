#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		using container = typename std::stack<T>::container_type;
		using iterator = typename container::iterator;
		using reverse_iterator = typename container::reverse_iterator;
		using const_iterator = typename container::const_iterator;
		using const_reverse_iterator = typename container::const_reverse_iterator;
		
		iterator begin(){ return this->c.begin();}
		
		typename std::stack<T>::container_type::iterator end(){ return this->c.end(); } //long version without "using" keyword
		
		reverse_iterator rbegin(){ return this->c.rbegin(); }
		
		reverse_iterator rend(){ return this->c.rend(); }
		
		const_iterator cbegin(){ return this->c.cbegin(); }
		
		const_iterator cend(){ return this->c.cend(); }
		
		const_reverse_iterator crbegin(){ return this->c.crbegin(); }
		
		const_reverse_iterator crend(){ return this->c.crend(); }	

};

#endif

/*

std::stack:

is a container adaptor that uses an encapsulated object of a 
specific container class as its underlying container, 
providing a specific set of member functions to access its elements. 

typename std::stack<T>::container_type::iterator: 

This defines iterator as alias for the iterator type of the underlying container 
of std::stack<T>.
Using the protected c member of std::stack to access function of the underlying container.
The c member is a protected member of the std::stack class template 
which MutantStack is inheriting from.

*/