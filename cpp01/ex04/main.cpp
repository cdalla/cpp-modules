/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 11:02:47 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/17 11:56:03 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void myReplace(std::string& str, std::string &str1, std::string &str2);

int main(int argc, char* argv[])
{
	std::string		filename;
	std::string		str1;
	std::string		str2;
	std::string		strRead;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments!!!" << std::endl;
		return (0);
	}
	filename = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	std::ifstream 	ifs(filename);
	if (!ifs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (0);
	}
	std::ofstream	ofs(filename + ".replacement");
	while (ifs)
	{
		std::getline(ifs, strRead);
		myReplace(strRead, str1, str2);
		ofs << strRead << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}

