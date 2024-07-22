#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <algorithm>

class Span
{
	private:
	
		unsigned int		_N;
		std::vector<int>	_elements;

	public:
	
		Span();
		Span(unsigned int N);
		~Span();
		
		Span(Span const &src);
		Span &operator=(Span const &src);
		
		int		shortestSpan();
		int		longestSpan() const;
		void	addNumber(int element);
		void	addRandomNumbers(int amount);
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

	class FullSpan : public std::exception
	{
		public:
	
			virtual const char* what() const throw();
	};

	class EmptySpan : public std::exception
	{
	public:
		
		virtual const char* what() const throw();
	};

};




#endif