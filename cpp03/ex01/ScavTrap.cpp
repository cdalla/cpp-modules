/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 11:35:23 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/22 12:42:37 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called with parameters" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	*this = src;
	
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;

	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;

	this->_name = src.getName();

	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;

	return ;
}

void	ScavTrap::attack(const std::string & target)
{
	this->_energyPoints = this->getEnergy() - 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " point of damage" << std::endl;

	return ;
}