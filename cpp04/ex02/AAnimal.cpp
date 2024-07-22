/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 14:56:14 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/25 15:27:59 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor" << std::endl;

	return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
	*this = src;

	std::cout << "AAnimal copy constructor called" << std::endl;
	
	return ;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
	this->_type = src.getType();

	std::cout << "AAnimal copy assignment operator called" << std::endl;

	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;

	return ;
}

std::string	AAnimal::getType(void) const
{
	return this->_type;
}

void AAnimal::makeSound(void) const
{
	std::cout << "E il coccodrillo come fa????" << std::endl;

	return ;
}

void	AAnimal::explainIdeas(void) const
{
	return ;
}
