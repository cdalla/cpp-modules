/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/11 14:46:08 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/12 12:14:46 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	_name = name;
	announce();
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name <<" destroyed" << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraaiiinnzzzzZ..." << std::endl;
	return; 
}
