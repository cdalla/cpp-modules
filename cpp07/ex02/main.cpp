// #include "Array.hpp"
// #include <iostream>

// int	main(void)
// {
// 	Array<int> intArray;
// 	Array<float> floatArray(5);
	
// 	std::cout << "Empty array size: " << intArray.size() << std::endl;
// 	std::cout << "Non empty array size: " << floatArray.size() << std::endl;
	
// 	try
// 	{
// 		//floatArray[-1] = 1;
// 		std::cout << "Empty array:\n" << intArray[0] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Index out of bounds" << std::endl;
// 	}
	
// 	try
// 	{

// 		std::cout << "Non empty array:\n" << floatArray[0] << std::endl;
// 		floatArray[0] = 1.1;
// 		std::cout << floatArray[0] << std::endl;
// 		std::cout << floatArray[5] << std::endl;
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Index out of bounds" << std::endl;
// 	}
	
// 	//DEFAULT INITIALIZATION EXAMPLE
// 	// int *a = new int();
	
// 	// std::cout << *a << std::endl;
	
// 	return 0;
// }


#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid index" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Index out of bounds" << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}