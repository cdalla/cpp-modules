#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
# include <iostream>

class NoOccurence : public std::exception
{
	public:

		virtual const char* what() const throw()
		{
			return("No occurence found");
		}
};

template <typename T>
typename T::iterator easyfind(T & container, int element)
{
	typename T::iterator first = std::find (container.begin(), container.end(), element);
	
	if (first != container.end())
		return first;
	else
		throw NoOccurence();
	
}

#endif