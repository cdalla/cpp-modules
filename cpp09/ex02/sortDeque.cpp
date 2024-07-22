#include "PmergeMe.hpp"

void	printPairDeque(std::deque<std::pair<int,int>>&deque)
{
	std::deque<std::pair<int,int>>::iterator it;
	for (it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void	insertBinary(std::deque<int>& deque, int element, unsigned int range)
{
	std::deque<int>::iterator it = std::upper_bound(deque.begin(), deque.begin() + range, element);
	deque.insert(it, element);
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
void	PmergeMe::insertMergeD(std::deque<int>& sorted, std::deque<int>& toSort)
{
	int sizeToSort = toSort.size();
	int inserted = 0;
	
	sorted.insert(sorted.begin(), toSort[0]);
	inserted++;
	std::deque<int>::iterator it;
	for (it  = _jacobsthalNumDeque.begin() + 1; it != _jacobsthalNumDeque.end(); ++it)
	{
		for (int i = std::min(*it, sizeToSort - 1); i > 0 && i > *(it - 1); i--)
		{
			insertBinary(sorted, toSort[i], inserted + i);
			inserted++;
		}
	}
	
	//if odd number of elements insert last element of input sequence
	if (_nDeSequence.size() % 2)
		insertBinary(sorted, _nDeSequence.back(), sorted.size());
}

void	sortPairDeque(std::deque<std::pair<int,int>> &deque, size_t index)
{	
	size_t j = deque.size() - 1;
	while (j > index)
	{
		if (deque[j].first < deque[j - 1].first)
			std::swap (deque[j], deque[j - 1]);
		j--;
	}
	if (index == deque.size() - 1)
		return ;
	return (sortPairDeque(deque, index + 1));
}

void	PmergeMe::makeSortPairD(std::deque<int>& sorted, std::deque<int>& toSort)
{
	unsigned int pairNum = _nDeSequence.size() / 2;
	std::deque<std::pair<int,int>>	pairDeque;
	
	for (size_t i = 0; i < pairNum; i++)
	{
		int j = i * 2;
		if (_nDeSequence[j] > _nDeSequence[j + 1])
			pairDeque.push_back(std::pair<int,int>(_nDeSequence[j], _nDeSequence[j + 1]));
		else
			pairDeque.push_back(std::pair<int,int>(_nDeSequence[j + 1], _nDeSequence[j]));
	}
	
	sortPairDeque(pairDeque, 0);
	for (size_t i = 0; i < pairNum; i++)
	{
		sorted.push_back(pairDeque[i].first);
		toSort.push_back(pairDeque[i].second);
	}
}
