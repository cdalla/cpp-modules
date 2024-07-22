/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 12:18:51 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/21 14:19:25 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main (void)
{
	ClapTrap jonny("Jonny");
	ClapTrap bonny("Bonny");

	std::cout << "Jonny has " << jonny.getHitPoints() << " health and " << jonny.getEnergy() << " energy points." << std::endl;
	std::cout << "Jonny has " << bonny.getHitPoints() << " health and " << bonny.getEnergy() << " energy points." << std::endl;
	std::cout << "\n";

	while (jonny.getEnergy() > 0)
	{
		if (bonny.getHitPoints() == 1)
			bonny.beRepaired(2);
		if (bonny.getHitPoints() <= 0)
		{
			std::cout  << "Poor Bonny, he is dead" << std::endl;
			break ; 
		}
		if (jonny.getEnergy() == 0)
		{
			std::cout << "Jonny has no more energy to attack" << std::endl;
			break ;
		}
		jonny.attack("Bonny");
		bonny.takeDamage(jonny.getAttackDamage());
		std::cout << "\n";
	}
	
	return (0);
}
