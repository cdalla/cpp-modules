#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int 		intArray [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float		floatArray[5] = {3.0f, 14.3f, 1.1f};
	std::string stringArray[3] = {"ciao", "come", "stai"};
	
	std::cout << "INT ARRAY" << std::endl;
	::iter(intArray, 10, printFunct<int>);
	std::cout << "FLOAT ARRAY" << std::endl;
	::iter(floatArray, 5, printFunct<float>);
	std::cout << "STRING ARRAY" << std::endl;
	::iter(stringArray, 3, printFunct<std::string>);
	return 0;
}