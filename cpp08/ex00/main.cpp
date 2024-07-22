#include "easyfind.hpp"
#include <list>
#include <array>
#include <vector>
#include <deque>

int main (void)
{
	
	//LIST
	std::cout << "LIST" << std::endl;
	try
	{
		std::list<int>	lst;
		
		for (int i = 0; i < 3; i++)
			lst.push_back(i + 1);
	
		std::list<int>::iterator index = ::easyfind(lst, 2);
		
		std::cout << "Found element "<< *index << " at position " << std::distance(lst.begin(), index) << " in the list" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//ARRAY
	std::cout << "\nARRAY" << std::endl;
	try
	{
		std::array<int, 3> arr = {1, 2, 3};
	
		std::array<int, 3>::iterator index = ::easyfind(arr, 4);
		
		std::cout << "Found element "<< *index << " at position " << std::distance(arr.begin(), index) << " in the array" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//VECTOR
	std::cout << "\nVECTOR" << std::endl;
	try
	{
		std::vector<int> vec = {1, 2, 3, 4, 5};
	
		std::vector<int>::iterator index = ::easyfind(vec, 4);
		
		std::cout << "Found element "<< *index << " at position " << std::distance(vec.begin(), index) << " in the array" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//DEQUE
	std::cout << "\nDOUBLE ENDED QUEUE" << std::endl;
	try
	{
		std::deque<int> deq;
		
		deq.push_back(1);
		deq.push_front(2);
		deq.insert(deq.begin(), 10);
		
		std::deque<int>::iterator index = ::easyfind(deq, 10);
		
		std::cout << "Found element "<< *index << " at position " << std::distance(deq.begin(), index) << " in the array" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}