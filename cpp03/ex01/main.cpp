/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 12:18:51 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/22 12:42:06 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main (void)
{
	ClapTrap jonny("Jonny");
	ClapTrap bonny("Bonny");
	ScavTrap holly("Holly");

	std::cout << jonny.getName() << " has " << jonny.getHitPoints() << " health and " << jonny.getEnergy() << " energy points." << std::endl;
	std::cout << bonny.getName() << " has " << bonny.getHitPoints() << " health and " << bonny.getEnergy() << " energy points." << std::endl;
	std::cout << holly.getName() << " has " << holly.getHitPoints() << " health and " << holly.getEnergy() << " energy points." << std::endl;
	std::cout << "\n";

	while (jonny.getEnergy() >= 0)
	{
		if (holly.getHitPoints() == 1)
			holly.beRepaired(2);
		if (holly.getHitPoints() <= 0)
		{
			std::cout  << "Poor Holly, he is dead" << std::endl;
			break ; 
		}
		if (jonny.getEnergy() == 0)
		{
			std::cout << "Jonny has no more energy to attack" << std::endl;
			break ;
		}
		jonny.attack("Bonny");
		holly.takeDamage(jonny.getAttackDamage());
		std::cout << "\n";
	}
	
	std::cout << "\n";
	holly.guardGate();
	std::cout << "\n";
	
	while (holly.getEnergy() >= 0)
	{
		if (bonny.getHitPoints() == 1)
			bonny.beRepaired(2);
		if (bonny.getHitPoints() <= 0)
		{
			std::cout  << "Poor Bonny, he is dead" << std::endl;
			break ; 
		}
		if (holly.getEnergy() == 0)
		{
			std::cout << "Holly has no more energy to attack" << std::endl;
			break ;
		}
		holly.attack("Bonny");
		bonny.takeDamage(jonny.getAttackDamage());
		std::cout << "\n";
	}
	
	return (0);
}
