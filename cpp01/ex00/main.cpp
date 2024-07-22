/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/11 15:01:41 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/12 10:43:50 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie*	newZombie(std::string _name)
{
	return (new Zombie(_name));
}

void	randomChump(std::string _name)
{
	Zombie _zombie(_name);
	return;
}

int	main(void)
{
	std::string	name1 = "Heap Zombie";
	std::string name2 = "Stack Zombie";
	Zombie* nZombie;

	nZombie = newZombie(name1);
	randomChump(name2);

	delete(nZombie);
	//system("leaks Brainz");
	return (0);
}