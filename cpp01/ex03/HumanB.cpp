/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 13:49:51 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/01 10:36:40 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::attack(void)
{
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their melting toxic fart" << std::endl;
	else	
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return;
}