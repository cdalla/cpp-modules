/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:17:26 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/08/05 10:59:47 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	//TO TEST AANIMAL IL ABSTRACT	
		//AAnimal  c();
	//TEST DEEP COPY
	// {
	// 	Dog first;
	// 	{
	// 		Dog second (first);
	// 	}
	// }
	//TEST OUTPUT IDEAS
	{
		const AAnimal* a = new Cat();
		const AAnimal* b = new Dog();

		//std::cout << a->getType() << std::endl;

		a->explainIdeas();
		b->explainIdeas();
		delete a;
		delete b;
	}
	//TEST FOR ARRAY
	// std::cout << "\n";
	// {
	// 	const AAnimal* homeJungle[4];
	// 	for (int i = 0; i < 2; i++)
	// 		homeJungle[i] = new Cat();
	// 	for (int i = 2; i < 4; i++)
	// 		homeJungle[i] = new Dog();
	// 	for (int i = 0; i < 4; i++)
	// 		delete homeJungle[i];
	// }	
	//system("leaks -q Animal");
	return 0;
}
