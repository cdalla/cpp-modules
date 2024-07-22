/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/11 12:09:51 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/11 12:10:01 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j]; j++)
				std::cout << char(toupper(argv[i][j]));
			std::cout << " ";
		}
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
