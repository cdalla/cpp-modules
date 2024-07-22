/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:42:44 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/24 15:51:38 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;

	*this = src;

	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;

	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout << "Wrong animal copy assignment operator called" << std::endl;

	this->_type = src.getType();

	return *this;
}

void 	WrongAnimal::makeSound(void) const
{
	std::cout << "ouchocuhocuh iamwrong ouch" << std::endl;

	return ;
}

std::string		WrongAnimal::getType(void) const
{
	return this->_type;
}