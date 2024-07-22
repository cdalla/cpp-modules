/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:17:26 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/05 10:55:00 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	//TEST DEEP COPY
	// {
	// 	Dog first;
	// 	{
	// 		Dog second (first);
	// 	}
	// }
	//TEST OUTPUT IDEAS
	{
		const Animal* a = new Cat();
		const Animal* b = new Dog();

		a->explainIdeas();
		b->explainIdeas();
		delete a;
		delete b;
	}
	// std::cout << "\n";
	// {
	// 	const Animal* homeJungle[4];
	// 	for (int i = 0; i < 2; i++)
	// 		homeJungle[i] = new Cat();
	// 	std::cout << "\n";
	// 	for (int i = 2; i < 4; i++)
	// 		homeJungle[i] = new Dog();
	// 	std::cout << "\n";
	// 	for (int i = 0; i < 4; i++)
	// 		delete homeJungle[i];
	// }	
	system("leaks -q Animal");
	return 0;
}