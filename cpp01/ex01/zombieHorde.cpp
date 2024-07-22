/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 10:47:02 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/01 10:28:16 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[10];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	
	return horde;
}