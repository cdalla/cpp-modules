/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 11:06:55 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/20 12:14:30 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;

	this->_fix = 0;
	
	return ;
}

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	
	//conversion int to fixed
	_fix = src << _fracBits;
	
	return ;
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;

	//conversion float to fixed
	_fix = std::roundf(src * (1 << _fracBits));

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

//GETTER

int		Fixed::getRawBits(void) const
{
	//std::cout <<  "getRawBit member function called" << std::endl;
	return this->_fix;
}

//SETTER

void	Fixed::setRawBits(int const raw)
{
	this->_fix = raw;
	return ;
}

//CONVERSION

float	Fixed::toFloat(void) const
{
	//conversion fixed to float
	return static_cast<float>(this->getRawBits()) / (1 << _fracBits);
}

int		Fixed::toInt(void) const
{
	//conversion fixed to int
	return this->getRawBits() >> _fracBits; 
}

//OPERATORS OVERLOAD

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	this->_fix = src.getRawBits();

	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}
