/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:12:20 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/24 15:37:34 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog default constructor" << std::endl;

	_type = "Dog";

	return;
}

Dog::Dog(Dog const & src)
{
	*this = src;

	std::cout << "Dog copy constructor called" << std::endl;

	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;

	return ;
}

Dog & Dog::operator=(Dog const & src)
{
	this->_type = src.getType();
	
	std::cout << "Dog copy assignment operator called" << std::endl;

	return *this;
}


void Dog::makeSound(void) const
{
	std::cout << "Baubauabaubbdbuaabdd" << std::endl;

	return ;
}