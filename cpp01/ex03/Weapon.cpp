/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 12:23:02 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/13 12:27:15 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string const & Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return;
}
