/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 14:56:14 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/25 11:54:01 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal default constructor" << std::endl;

	return ;
}

Animal::Animal(Animal const & src)
{
	*this = src;

	std::cout << "Animal copy constructor called" << std::endl;
	
	return ;
}

Animal & Animal::operator=(Animal const & src)
{
	this->_type = src.getType();

	std::cout << "Animal copy assignment operator called" << std::endl;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;

	return ;
}

std::string	Animal::getType(void) const
{
	return this->_type;
}

void Animal::makeSound(void) const
{
	std::cout << "E il coccodrillo come fa????" << std::endl;

	return ;
}

void	Animal::explainIdeas(void) const
{
	return ;
}
