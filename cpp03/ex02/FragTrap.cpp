/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 14:14:36 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/24 10:53:08 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	
	std::cout << "FragTrap default constructor called" << std::endl;
	
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	
	std::cout << "FragTrap constructor with parameters called" << std::endl;

	return ;
}
		
FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;

	*this = src;

	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;

	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;

	this->_name = src.getName();

	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Yo, FragTrap " << this->getName() << " wants an HighFive really bad :)" << std::endl;

	return ;
}

void FragTrap::attack(const std::string & target)
{
	this->_energyPoints = this->getEnergy() - 1;
	 
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage 
				<< " point of damage, " << this->getName() << " has now " << this->getEnergy() << "energy points" << std::endl;

	return ;
}
