/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   myReplace.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 12:04:20 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/17 11:56:00 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>

//str1 to be replaced with str2
void myReplace(std::string& str, std::string &str1, std::string &str2)
{
	std::string		newStr;

	size_t 			pos = str.find(str1);
	while (pos != std::string::npos)
	{
		str.erase(pos, str1.length());
		str.insert(pos, str2);
		pos = str.find(str1);
	}
	return;
}
