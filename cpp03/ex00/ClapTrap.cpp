/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 11:19:52 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/22 12:39:20 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _hitPoints(10) , _energyPoints(10), _attackDamage(3)
{
	std::cout << "Clap Trap default constructor called" << std::endl;

	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10) , _energyPoints(10), _attackDamage(3)
{
	std::cout << "ClapTrap constructor called with parameter" << std::endl;

	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	
	return ; 
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;

	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	this->_name = src.getName(); 

	return *this;
}


std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int			ClapTrap::getEnergy(void) const
{
	return this->_energyPoints;
}

int			ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

int			ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

void	ClapTrap::attack(const std::string & target)
{
	this->_energyPoints = this->getEnergy() - 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " point of damage" << std::endl;

	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints = this->getHitPoints() - amount;
	
	std::cout << "ClapTrap " << this->_name << " take " << amount << " point of damage, has now " << this->getHitPoints() << " health point" << std::endl;

	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints = this->getHitPoints() + amount;

 	std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount << " points, has now " << this->getHitPoints() << " health point" << std::endl;

	return ; 
}
