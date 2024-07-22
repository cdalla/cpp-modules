/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:04:49 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/05 10:35:51 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat default constructor" << std::endl;

	_type = "Cat";
	
	return ;
}

Cat::Cat(Cat const & src)
{
	*this = src;

	std::cout << "Cat copy constructor called" << std::endl;

	return ;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
	this->_type = src.getType();

	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaoowoewoowwoww" << std::endl;

	return ;
}
