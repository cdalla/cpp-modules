/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/11 11:57:15 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/11 12:06:29 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	std::cout << "Contact created" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact deleted" << std::endl;
	return;
}

std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string Contact::getNickName(void) const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::getSecret(void) const
{
	return this->_darkestSecret;
}

void	Contact::setFirstName(std::string first)
{
	this->_firstName = first;
	return;
}

void	Contact::setLastName(std::string last)
{
	this->_lastName = last;
	return;
}

void	Contact::setNickName(std::string nick)
{
	this->_nickName = nick;
	return;
}

void	Contact::setPhoneNumber(std::string number)
{
	this->_phoneNumber = number;
	return;
}

void	Contact::setSecret(std::string secret)
{
	this->_darkestSecret = secret;
	return;
}
