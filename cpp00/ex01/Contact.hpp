/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:15:59 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/10 13:51:05 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iomanip>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		std::string	getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNumber(void) const;
		std::string getSecret(void) const;
		void		setFirstName(std::string first);
		void		setLastName(std::string last);
		void		setNickName(std::string nick);
		void		setPhoneNumber(std::string number);
		void		setSecret(std::string secret);
		
	private:

		std::string _firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		
};

#endif