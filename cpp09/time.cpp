#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main(void)
{
	std::string date = "2045-12-28";
	
	std::tm time;
	
	std::stringstream date_ss(date); //buffer the string, and use it as a stream input
	
	date_ss >> std::get_time(&time, "%Y-%m-%d"); //parse a stringstream in the time format specified by the second string
	
	if (date_ss.fail()) //
		std::cout << "no bueno" << std::endl;
	else
		 std::cout << std::put_time(&time, "%Y-%m-%d") << '\n'; //
	
	return 0;
}