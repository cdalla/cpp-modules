/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 12:00:39 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/17 12:55:26 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl itsYou;

	std::cout << "Debug message: ";
	itsYou.complain("DEBUG");
	std::cout << "Info message: ";
	itsYou.complain("INFO");
	std::cout << "Warning message: ";
	itsYou.complain("WARNING");
	std::cout << "Error message: ";
	itsYou.complain("ERROR");
	return (0);
}