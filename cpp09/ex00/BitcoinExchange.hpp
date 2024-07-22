#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <string>
# include <map>
# include <sstream>
# include <ctime>
# include <iomanip>

class BitcoinExchange
{
	private:
		
		std::ifstream				_csvFile;
		std::ifstream				_inputFile;
		std::map<std::string, float>	_csvContainer;
		
	public:
	
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		
		BitcoinExchange &operator=(BitcoinExchange const &src);
		
		void	saveCsvFile(std::string filename);
		void	printChangeValue(std::string filename);

};

class tooLargeNum : public std::exception
{
	public:
	
	virtual const char* what() const throw()
	{
		return ("Error: too large number");
	}
};

class notPositiveNum : public std::exception
{
	public:
	
	virtual const char* what() const throw()
	{
		return ("Error: not a positive number");
	}
};

class fileNotopen : public std::exception
{
	public:
	
	virtual const char* what() const throw()
	{
		return ("Error: could not open file");
	}
};

class badInput : public std::exception
{
	public:
	
	virtual const char* what() const throw()
	{
		return ("Error: bad input");
	}
};

class fileEmpty : public std::exception
{
	public:
	
	virtual const char* what() const throw()
	{
		return ("Error: file empty");
	}
};

#endif