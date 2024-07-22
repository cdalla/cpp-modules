/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 11:06:55 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/19 12:53:11 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;

	this->_fix = 0;
	
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout <<  "getRawBit member function called" << std::endl;
	return this->_fix;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fix = raw;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	this->_fix = src.getRawBits();

	return *this;
}