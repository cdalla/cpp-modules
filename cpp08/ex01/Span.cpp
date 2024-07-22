#include "Span.hpp"



Span::Span(void)
{
	//std::cout << "Span default constructor called" << std::endl;
	
	return ;
}

Span::Span(unsigned int N) : _N(N)
{
	//std::cout << "Span constructor with parameter called" << std::endl;
	
	return ;
}

Span::~Span(void)
{
	//std::cout << "Span destructor called" << std::endl;
	
	return ;
}

Span & Span::operator=(Span const &src)
{
	this->_N = src._N;
	this->_elements = src._elements; //= sign
	//this->_elements.assign(src._elements.begin(), src._elements.end()); // insert function
	//this->_elements.insert(this->_elements.begin(), src._elements.begin(), src._elements.end()); // assing function
	//std::copy(src._elements.begin(), src._elements.end(), back_inserter(this->_elements)); // copy algorithm
	return *this;
}

Span::Span(Span const & src)
{
	//std::cout << "Span copy constructor called" << std::endl;
	
	*this = src;
	
	return ;
}

int	Span::longestSpan() const
{
	if (this->_elements.size() > 1)
		return (*std::max_element(_elements.begin(), _elements.end())
					- *std::min_element(_elements.begin(), _elements.end()));
	else
		throw EmptySpan();
}

int	Span::shortestSpan()
{
	int min;
	
	if (this->_elements.size() > 1)
	{
		std::sort(_elements.begin(), _elements.end());
		min = _elements[1] - _elements[0];
		for (unsigned int i = 2; i < _elements.size(); i++)
			min = std::min(min,  (_elements[i] - _elements[i - 1]));
		return min;
	}
	else
		throw EmptySpan();
}

void	Span::addNumber(int element)
{
	if (_elements.size() < _N)
		_elements.push_back(element);
	else
		throw FullSpan();
}

void	Span::addRandomNumbers(int amount)
{
	if (_elements.size() + amount > _N)
		throw FullSpan();
	std::srand(time(NULL));
	
	for (int i = 0; i < amount; i++)
		_elements.push_back(std::rand() % (amount * 2));
	
	return ;
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) + _elements.size() > _N)
		throw FullSpan();
	
	_elements.insert(_elements.end(), start, end);
	
	return ;
}


const char* Span::FullSpan::what() const throw()
{
	return ("Span store is full");
}

const char* Span::EmptySpan::what() const throw()
{
	return ("Not enough elements for comparison");
}