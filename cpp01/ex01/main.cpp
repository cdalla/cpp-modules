/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/11 15:01:41 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/01 10:29:17 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int N = 10;

	Zombie* horde = zombieHorde(N, "Stucazz");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	//system("leaks Horde");
	return (0);
}