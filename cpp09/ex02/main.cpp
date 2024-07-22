#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe yoyo;
	if (argc < 3)
	{
		std::cerr << "Error: Wrong number of input elements" << std::endl;
		return 0;
	}
	try
	{
		yoyo.sort(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}


/*
	Merge-Insertion sorting algorithm:
	
	- divide the group of numbers(n) in (n/2) pairs
	
	- perform n/2 comparison, one for each pair set the greater element as first
	
	- recursively sort by the larger element of each pair to create
		a sorted sequence of n/2 elements S(Sorted container)
	
	- insert at the start of S the element paired with first and smallest element of S

	- using jacobsthal number, perform N comparison to find the correct position to insert second element
		of the pair in the sorted sequence
*/