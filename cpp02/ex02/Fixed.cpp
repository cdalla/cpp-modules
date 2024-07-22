/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 11:06:55 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/02 10:31:11 by cdalla-s      ########   odam.nl         */
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

int		Fixed::getRawBits(void) const
{
	//std::cout <<  "getRawBit member function called" << std::endl;
	return this->_fix;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fix = raw;
	return ;
}

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

//ARITHMETIC

Fixed	Fixed::operator+(Fixed const & src)
{
	return Fixed (this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const & src)
{
	return Fixed (this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed const & src)
{
	return Fixed (this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const & src)
{
	return Fixed (this->toFloat() / src.toFloat());
}

//COMPARISON 

bool	Fixed::operator>(Fixed const & src) const
{
	if (this->toFloat() > src.toFloat())
		return  true;
	else
		return false;
}

bool	Fixed::operator<(Fixed const & src) const
{
	// if (this->toFloat() < src.toFloat())
	// 	return true;
	// else
	// 	return false;
	return src > *this;
}

bool	Fixed::operator>=(Fixed const & src) const
{
	// if (this->toFloat() >= src.toFloat())
	// 	return true;
	// else
	// 	return false;
	return !(src > *this);
}

bool	Fixed::operator<=(Fixed const & src) const
{
	// if (this->toFloat() <= src.toFloat())
	// 	return true;
	// else
	// 	return false;
	return !(src < *this);
}

bool	Fixed::operator==(Fixed const & src) const
{
	if (this->toFloat() == src.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(Fixed const & src) const
{
	// if (this->toFloat() != src.toFloat())
	// 	return true;
	// else
	// 	return false;
	return !(*this == src);
}

//PREFIX - POSTFIX

Fixed &	Fixed::operator++()
{
	int		tmp;

	tmp = this->_fix;
	this->_fix = ++tmp;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;

	tmp._fix = this->_fix++;
	
	return tmp;
}

Fixed & Fixed::operator--()
{
	int		tmp;

	tmp = this->_fix;
	this->_fix = --tmp;
	
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp;

	tmp._fix = this->_fix--;

	return tmp;
}

Fixed & Fixed::min(Fixed & num1, Fixed & num2)
{
	if (num1 <= num2)
		return num1;
	return num2;	
}

const Fixed & min(Fixed const & num1, Fixed const & num2)
{
	if (num1 <= num2)
		return num1;
	return num2;
}

Fixed & Fixed::max(Fixed & num1, Fixed & num2)
{
	if (num1 >= num2)
		return num1;
	return num2;
}

const Fixed & Fixed::max(Fixed const & num1, Fixed const & num2)
{
	if (num1 >= num2)
		return num1;
	return num2;
}