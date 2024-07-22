/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:53:14 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/05 10:35:28 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>


WrongCat::WrongCat()
{
	_type = "WrongCat";
	
	std::cout << "WrongCat default constructor called" << std::endl;

	return ;
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;

	*this = src;

	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;

	return ;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
	this->_type = src.getType();

	std::cout << "WrongCat copy assignment operator called" << std::endl;

	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Chipchipchip" << std::endl;
}

