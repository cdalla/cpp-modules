/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:12:20 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/25 12:38:46 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{

	this->_dogBrain = new Brain("Doggy idea");
	_type = "Dog";

	std::cout << "Dog default constructor" << std::endl;
	return;
}

Dog::Dog(Dog const & src)
{
	
	this->_dogBrain = new Brain();
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
	
	return ;
}

Dog::~Dog()
{
	delete _dogBrain;
	std::cout << "Dog destructor called" << std::endl;

	return ;
}

Dog & Dog::operator=(Dog const & src)
{
	this->_type = src.getType();
	*(this->_dogBrain) = *(src._dogBrain);
	
	std::cout << "Dog copy assignment operator called" << std::endl;

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Baubauabaubbdbuaabdd" << std::endl;

	return ;
}

void Dog::explainIdeas(void) const
{
	for(int i = 0; i < 100; i++)
		std::cout << this->_dogBrain->getIdeas(i) << std::endl;
	return;
}