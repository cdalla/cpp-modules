#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>

#define CHAR_TYPE		1
#define	INT_TYPE		2
#define FLOAT_TYPE		3
#define DOUBLE_TYPE		4
#define PSEUDO_TYPE		5
#define INVALID_INPUT	6

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	(void) src;
	
	return *this;
}


int	charCounter(char c, std::string param)
{
	int	count = 0;
	
	for(int i = 0; i < (int)param.length(); i++)
	{
		if (param.at(i) == c)
			count++;
	}
	return count;
}

bool	isValid(std::string	param, int dotCount)
{
	if (dotCount > 1)
		return false;														//literal with more than one '.' not valid
	if (param.find_first_not_of("0123456789.fFeE+-") != std::string::npos)	//check for char not use for num literals
			return false;
	if (dotCount == 0)														//integer
	{
		for (int i = 0; i < (int)param.length(); i++)
		{
			if(!std::isdigit(param.at(i)) && !(i == 0 && (param.at(i) == '+' || param.at(i) == '-')))
				return false;
		}
	}
	else																	// float or double
	{
		if (charCounter('E', param) > 1 || charCounter('e', param) > 1
			|| (charCounter('e', param) && charCounter('E', param)))
			return false;
		for (int i = 0; i < (int)param.length(); i++)
		{
			if (param.at(i) == '+' || param.at(i) == '-')
			{
				if (i == (int)param.length() - 1)
					return false;
				else if (i > 0 && (param.at(i - 1) != 'e' && param.at(i - 1) != 'E'))
					return false;
				else if (i > 0 && (!std::isdigit(param.at(i + 1))))
					return false;
			}
			else if (param.at(i) == 'e' || param.at(i) == 'E')
			{
				if (i == (int)param.length() - 1)
					return false;
				if (i < (int)param.find('.'))
					return false;
			}
			if ((param.at(i) == 'f' || param.at(i) == 'F') && i != (int)param.length() - 1)
				return false;
		}
	}
	return true;
}

bool	isChar(std::string param)
{
	if (param.size() == 1 && !isdigit(param.at(0)))
		return  true;
	return false;
}

bool	isPseudo(std::string param)
{
	std::string pseudo[] = {"-inff", "+inff", "inff", "nanf", "-inf", "+inf", "inf", "nan"};
	for (int i = 0; i < 8; i++)
	{
		if (pseudo[i] == param)
			return true;
	}
	return false;
}

int	typeDetermine(std::string const param)
{
	if (isChar(param))
		return CHAR_TYPE;
	else if (isPseudo(param))
		return PSEUDO_TYPE;
	
	int	dotCount = charCounter('.', param);
	if (!isValid(param, dotCount))
		return INVALID_INPUT;
	if (dotCount == 0)
	{
		try
		{
			stoi(param);
			return INT_TYPE;
		}
		catch (std::exception &e){}
	}
	if (param.at(param.length() - 1) == 'f' || param.at(param.length() - 1) == 'F')
	{
		try
		{
			stof(param);
			return FLOAT_TYPE;
		}
		catch (std::exception &e){}
	}
	else
	{
		try
		{
			stod(param);
			return DOUBLE_TYPE;
		}
		catch (std::exception &e){}
	}
	return INVALID_INPUT;
}

void	printChar(int i)
{
	if (i < 0 || i > 127)
		std::cout << "char: Not valid value" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
}

void	printFloatDouble(float f, double d)
{
	std::cout	<< std::fixed << std::setprecision(2)
			 	<< "float: " << f << "f\n"
				<< "double: " << d << std::endl;
}

void	printFloatToInt(float f)
{
	if (f < static_cast<float>( std::numeric_limits<int>::min())
		|| f > static_cast<float>( std::numeric_limits<int>::max()))
		std::cout << "int: Out of int range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
}

void	printDoubleToInt(double d)
{
	if (d < static_cast<double>( std::numeric_limits<int>::min())
		|| d > static_cast<double>( std::numeric_limits<int>::max()))
		std::cout << "int: Out of int range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void	ScalarConverter::convert(std::string param)
{
	int			type;
	int			intRepr;
	double		doubleRepr;
	float		floatRepr;
	char		charRepr;
	
	type = typeDetermine(param);
	
	switch (type)
	{
		case INT_TYPE:
			intRepr = stoi(param);
			printChar(intRepr);
			std::cout << "int: " << intRepr << std::endl;
			printFloatDouble(static_cast<float>(intRepr), static_cast<double>(intRepr));
			break;
		case CHAR_TYPE:
			charRepr = param.at(0);
			printChar(charRepr);
			std::cout << "int: " << static_cast<int>(charRepr) << std::endl;
			printFloatDouble(static_cast<float>(charRepr), static_cast<double>(charRepr));
			break;
		case FLOAT_TYPE:
			floatRepr = stof(param);
			printChar(static_cast<int>(floatRepr));
			printFloatToInt(floatRepr);
			printFloatDouble(floatRepr, static_cast<double>(floatRepr));
			break;
		case DOUBLE_TYPE:
			doubleRepr = stod(param);
			printChar(static_cast<int>(doubleRepr));
			printDoubleToInt(doubleRepr);
			printFloatDouble(static_cast<float>(doubleRepr), doubleRepr);
			break;
		case PSEUDO_TYPE:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			printFloatDouble(stof(param), stod(param));
			break;
		case INVALID_INPUT:
			std::cerr << "Invalid input: " << param << std::endl;
			break;
	}
	return ;
}

