/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 13:58:16 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/25 16:03:52 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	std::cout << "You have a new PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook got lost" << std::endl;
	return;
}

bool	PhoneBook::str_digit(std::string _str)
{
	if (_str.empty())
		return false;
	for(size_t i = 0; i < _str.length(); i++)
	{
		if(!std::isdigit(_str[i]))
			return (false);
	}
	return (true);
}

void	PhoneBook::add_f(void)
{
	static int _counter = 0;
	std::string _first;
	std::string	_last;
	std::string	_nick;
	std::string _number;
	std::string	_secret;

	if (_counter == 8)
		_counter = 0;
	std::cout << "ADD A NEW CONTACT" << std::endl;
	
	while (std::cout << "INSERT FIRST NAME: " && std::getline(std::cin, _first) && _first.empty());
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	this->contacts[_counter].setFirstName(_first);
	
	while (std::cout << "INSERT LAST NAME: " && std::getline (std::cin, _last) && _last.empty());
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	this->contacts[_counter].setLastName(_last);
	
	while (std::cout << "INSERT NICKNAME: " && std::getline(std::cin,_nick) && _nick.empty());
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	this->contacts[_counter].setNickName(_nick);
	
	while (std::cout << "INSERT PHONE NUMBER: " && std::getline(std::cin, _number) && !str_digit(_number))
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	this->contacts[_counter].setPhoneNumber(_number);
	
	while (std::cout << "TELL ME YOUR DARKEST SECRET: " && std::getline(std::cin, _secret) && _secret.empty())
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	this->contacts[_counter].setSecret(_secret);
	 _counter++;
	return;
}

void	PhoneBook::printContact()
{
	std::string	_strIndex;
	int 		_index;

	std::cout << "WHICH CONTACT DO U WANT TO SEE (index): ";
	if (!std::getline(std::cin, _strIndex))
	{
		if (std::cin.eof())
			exit(EXIT_FAILURE);
	}
	if (_strIndex.empty() || PhoneBook::str_digit(_strIndex) == false)
	{
		printContact();
		return;
	}
	_index = stoi(_strIndex);
	if (_index > 8 || _index < 1)
	{
		PhoneBook::printContact();
		return;
	}
	std::cout << std::setw(16) << "FIRST NAME: " << this->contacts[_index - 1].getFirstName() << std::endl;
	std::cout << std::setw(16) << "LAST NAME: " << this->contacts[_index - 1].getLastName() << std::endl;
	std::cout << std::setw(16) << "NICKNAME: " << this->contacts[_index - 1].getNickName() << std::endl;
	std::cout << std::setw(16) << "PHONE NUMBER: " << this->contacts[_index - 1].getPhoneNumber() << std::endl;
	std::cout << std::setw(16) << "DARKEST SECRET: " << this->contacts[_index - 1].getSecret() << std::endl;
	return;
}

void	PhoneBook::printGridLine(int _index, std::string _first, std::string _last, std::string _nick)
{

	std::cout << "|" << std::setw(11) << _index + 1;
	if (_first.length() > 10)
	{
		_first.resize(9);
		_first += '.';
	}
	std::cout << "|" << std::setw(11) << _first;
	if (_last.length() > 10)
	{
		_last.resize(9);
		_last += '.';
	}
	std::cout << "|" << std::setw(11) << _last;
	if (_nick.length() > 10)
	{
		_nick.resize(9);
		_nick += '.';
	}
	std::cout << "|" << std::setw(11) << _nick << "|" << std::endl;
}

void	PhoneBook::search_f(void)
{
	//first table line
	std::cout << "|" << std::setw(11) << "INDEX"<< "|";
	std::cout << std::setw(11) << "FIRST NAME" << "|";
	std::cout << std::setw(11) << "LAST NAME" << "|";
	std::cout << std::setw(11) << "NICKNAME" << "|" << std::endl;

	// print contacts table
	for(int i = 0; i < 8; i++)
		printGridLine(i, this->contacts[i].getFirstName(), this->contacts[i].getLastName(), this->contacts[i].getNickName());
	std::cout << std::endl;
	printContact();
	return;
}
