/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 13:52:19 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/26 10:13:50 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	public:
		
		PhoneBook(void);
		~PhoneBook(void);

		void	add_f(void);
		void	search_f(void);
	
	private:

		bool	str_digit(std::string str);
		void	printContact(void);
		void	printGridLine(int _index, std::string _first, std::string _last, std::string _nick);
		Contact contacts[8];
		
};

#endif

//index to add in the right position in the contact array
//when index == 8, set it to 0