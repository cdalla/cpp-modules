#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default BTC constructor called" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	
	std::cout << "Copy BTC constructor called" << std::endl;
	
	return ;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default BTC destructor called" << std::endl;
	
	_csvContainer.clear();
	
	return ;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &src)
{
	this->_csvContainer = src._csvContainer;
	
	return *this;
}

void	dateCheck(std::string date)
{
	std::tm time;
	std::stringstream date_ss(date);
	
	date_ss >> std::get_time(&time, "%Y-%m-%d"); //parse a stringstream in the time format specified by the second string
	if (date_ss.fail())
		throw std::runtime_error("Error: bad input => " + date); //date not valid
}

void	BitcoinExchange::saveCsvFile(std::string filename)
{
	std::string	dataString;
	
	if (filename.compare(filename.size() - 4, 4, ".csv"))
		throw badInput();
	_csvFile.open(filename);
	if (!_csvFile.is_open())
		throw fileNotopen();
	_csvFile.seekg(0, std::ios::end); // put the "cursor" at the end of the file
	if (!_csvFile.tellg())// find the position of the cursor
		throw fileEmpty();
	_csvFile.seekg(0, std::ios::beg); //reset cursor	
		
	while (std::getline(_csvFile, dataString))
	{
		try
		{
			if (!dataString.compare("date,exchange_rate"))
				continue ;
			std::string date = dataString.substr(0, dataString.find(',')); //check valid date
			dateCheck(date);
			_csvContainer[date] = std::stof(dataString.substr(dataString.find(',') + 1)); //check conversion
		}
		catch( const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	_csvFile.close();
	
	//PRINT MAP CONTENT
	// std::map<std::string, float>::iterator it = _csvContainer.begin();
	// for (; it != _csvContainer.end(); it++)
	// 	std::cout << it->first << ", " << it->second << std::endl;	
}

void BitcoinExchange::printChangeValue(std::string filename)
{
	if (filename.compare(filename.size() - 4, 4, ".txt"))
		throw badInput();
	_inputFile.open(filename);
	if (!_inputFile.is_open())
		throw fileNotopen();
	_inputFile.seekg(0, std::ios::end); // set position at last character
	if (!_inputFile.tellg()) // tellg return pos of the current character, if it is at the end and pos = 0, file empty
		throw fileEmpty();
	_inputFile.seekg(0, std::ios::beg); //reset cursor
	std::string inputString;
	if (_csvContainer.empty())
		throw std::runtime_error("Error: database empty");
	
	while (std::getline(_inputFile, inputString))
	{
		try
		{
			if (!inputString.compare("date | value"))
				continue ;
			std::string	date = inputString.substr(0, inputString.find('|'));
			dateCheck(date);
			std::string valueString = inputString.substr(inputString.find('|') + 1);
			if (valueString.find_first_not_of("0123456789-|. ") != std::string::npos)
				throw std::runtime_error("Error: bad input => " + valueString);
			else if(!valueString.length())
				throw std::runtime_error("Error: bad input => empty value");
			float	value = std::stof(valueString);
			if (value > 1000)
				throw tooLargeNum();
			else if (value < 0)
				throw notPositiveNum();
			std::map<std::string, float>::iterator it = _csvContainer.lower_bound(date);
			if (it->first > date)
			{
				if(it == _csvContainer.begin())
					throw std::runtime_error("Error: first date available: " + _csvContainer.begin()->first);//date out of bounds
				else
					std::cout << date << " => " << value << " = " << value * std::prev(it)->second << std::endl;//previous date
			}
			else if(it == _csvContainer.end())
				std::cout << date << " => " << value << " = " << value * _csvContainer.rbegin()->second << std::endl; //last value
			else
				std::cout << date << " => " << value << " = " << value * it->second << std::endl; //value found
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	_inputFile.close();
}
