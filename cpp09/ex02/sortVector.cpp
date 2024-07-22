#include "PmergeMe.hpp"

void	printPairVector(std::vector<std::pair<int,int>>&vec)
{
	std::vector<std::pair<int,int>>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void	insertBinary(std::vector<int>& vect, int element, unsigned int range)
{
	std::vector<int>::iterator it = std::upper_bound(vect.begin(), vect.begin() + range, element);
	vect.insert(it, element);
}

/*
- insert the first element of toSort as first element of Sorted, as it is smaller than his paired one
- skip 0 in jacobsthal sequence
- use jacobsthal number to know how many max comparison are needed
- if jacobsthal num > total elements take total elements, i greater than 0 (already in sorted)
	and greater than previous jacobsthal value, to exclude elements of toSort already inserted
- insert into sorted the i'th element, 
	with a comparison range increased by the number of elements already inserted
*/
void	PmergeMe::insertMergeV(std::vector<int>& sorted, std::vector<int>& toSort)
{
	int sizeToSort = toSort.size();
	int inserted = 0;
	
	sorted.insert(sorted.begin(), toSort[0]);
	inserted++;
	std::vector<int>::iterator it;
	for (it  = _jacobsthalNumVect.begin() + 1; it != _jacobsthalNumVect.end(); ++it)
	{
		for (int i = std::min(*it, sizeToSort - 1); i > 0 && i > *(it - 1); i--)
		{
			insertBinary(sorted, toSort[i], inserted + i);
			inserted++;
		}
	}
	
	//if odd number of elements insert last element of input sequence
	if (_nSequence.size() % 2)
		insertBinary(sorted, _nSequence.back(), sorted.size());
}

void	sortPairVect(std::vector<std::pair<int,int>> &vector, size_t index)
{	
	size_t j = vector.size() - 1;
	while (j > index)
	{
		if (vector[j].first < vector[j - 1].first)
			std::swap (vector[j], vector[j - 1]);
		j--;
	}
	if (index == vector.size() - 1)
		return ;
	return (sortPairVect(vector, index + 1));
}

void	PmergeMe::makeSortPairV(std::vector<int>& sorted, std::vector<int>& toSort)
{
	unsigned int pairNum = _nSequence.size() / 2;
	std::vector<std::pair<int,int>>	pairVect;
	
	for (size_t i = 0; i < pairNum; i++)
	{
		int j = i * 2;
		if (_nSequence[j] > _nSequence[j + 1])
			pairVect.push_back(std::pair<int,int>(_nSequence[j], _nSequence[j + 1]));
		else
			pairVect.push_back(std::pair<int,int>(_nSequence[j + 1], _nSequence[j]));
	}
	
	sortPairVect(pairVect, 0);
	//printPairVector(pairVect);
	for (size_t i = 0; i < pairNum; i++)
	{
		sorted.push_back(pairVect[i].first);
		toSort.push_back(pairVect[i].second);
	}
}