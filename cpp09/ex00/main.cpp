#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	BitcoinExchange myExchange;
	
	if (argc != 2)
	{
		std::cerr << "Need a input file name" << std::endl;
		return 0;
	}
	try
	{
		myExchange.saveCsvFile("data.csv");
		myExchange.printChangeValue(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
