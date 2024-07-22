#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
	
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);
		ScalarConverter & operator=(ScalarConverter const & src);	
	
	public:
		
		static void convert(std::string param);
};

#endif