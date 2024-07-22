/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:02:24 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/24 13:21:24 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main (void)
{
	std::string _action;
	PhoneBook _phoneBook;

	while (std::cout << "Select an action (ADD, SEARCH, EXIT): " && std::getline(std::cin, _action) && (_action != "EXIT"))
	{
		if (_action == "ADD")
			_phoneBook.add_f();
		else if (_action == "SEARCH")
			_phoneBook.search_f();
	}
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	return 0;
}
