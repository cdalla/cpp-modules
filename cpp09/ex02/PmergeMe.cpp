#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	
	return ;
}

PmergeMe::~PmergeMe()
{
	_nSequence.clear();
	_nDeSequence.clear();
	_jacobsthalNumDeque.clear();
	_jacobsthalNumVect.clear();
	return ;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &src)
{
	this->_nDeSequence = src._nDeSequence;
	this->_nSequence = src._nSequence;
	
	return *this;
}

bool	isPositive(std::string str)
{
	std::string::iterator it;
	
	for (it = str.begin(); it != str.end(); ++it)
	{
		if (!isdigit(*it))
			return false;
	}
	return true;
}

//in std::set every element is unique, can be filled with a range of iterators from another container
bool	checkDuplicate(std::vector<int> seq)
{
	std::set<int> duplicateChecker(seq.begin(), seq.end());
	
	//duplicateChecker.insert(seq.begin(), seq.end());
	
	return (seq.size() > duplicateChecker.size());
}

void	PmergeMe::parseInput(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '+')
			argv[i]++;
		if (!isPositive(argv[i]))
			throw std::runtime_error("Invalid elements in sequence");
		else
		{
			if (std::stoi(argv[i]) > INT_MAX)
				throw std::out_of_range("Value is out of integer range");
			else
				_nSequence.push_back(std::stoi(argv[i]));
		}
	}
	
	if (checkDuplicate(_nSequence))
		throw std::runtime_error("Duplicate values in sequence");
		
	return ;
}

void	PmergeMe::makeJacobsthalSequence(void)
{
	int a = 0;
	int b = 1;
	
	while (a <= this->_maxValue)
	{
		this->_jacobsthalNumVect.push_back(a);
		this->_jacobsthalNumDeque.push_back(a);
		int temp = a;
		a = b;
		b = b + 2 * temp;
	}
}

template <typename T>
void	printContainer(T& container)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << std::endl;
}

template < typename T>
bool	checkSorted(T & container)
{
	typename T::iterator  it;
	for (it = container.begin(); (it + 1) != container.end(); it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

void	PmergeMe::sort(int argc, char *argv[])
{	
	std::vector<int>	sortedV;
	std::vector<int>	toSortV;
	std::deque<int>		sortedD;
	std::deque<int>		toSortD;
	
	auto startParse = std::chrono::high_resolution_clock::now();
	parseInput(argc, argv);
	_maxValue = *(std::max_element(_nSequence.begin(), _nSequence.end()));
	_nDeSequence.assign(_nSequence.begin(), _nSequence.end());
	makeJacobsthalSequence();
	auto stopParse = std::chrono::high_resolution_clock::now();
	auto parseDuration = std::chrono::duration_cast<std::chrono::microseconds>(stopParse - startParse);
	
	if (checkSorted(_nSequence))
		throw std::runtime_error("Sequence already sorted");
	
	auto startVect = std::chrono::high_resolution_clock::now();
	makeSortPairV(sortedV, toSortV);
	insertMergeV(sortedV, toSortV);
	auto stopVect = std::chrono::high_resolution_clock::now();
	auto durationVect = std::chrono::duration_cast<std::chrono::microseconds>(stopVect - startVect);
	
	auto startDe = std::chrono::high_resolution_clock::now();
	makeSortPairD(sortedD, toSortD);
	insertMergeD(sortedD, toSortD);
	auto stopDe = std::chrono::high_resolution_clock::now();
	auto durationDe = std::chrono::duration_cast<std::chrono::microseconds>(stopDe - startDe);
	
	if (!checkSorted(sortedV))
		throw std::runtime_error("Vector not sorted");
	if (!checkSorted(sortedD))
		throw std::runtime_error("Deque not sorted");
	printResult(durationVect + parseDuration, durationDe + parseDuration, sortedV);
	return ;
}

void	PmergeMe::printResult(std::chrono::duration<double> vectTime, std::chrono::duration<double> dequeTime, std::vector<int>& sorted)
{
	std::cout << "Before:    ";
	for (size_t i = 0; i < _nSequence.size() && i < 20; i++)
		std::cout << _nSequence[i] << " ";
	if (_nSequence.size() > 20)
		std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << "After:     ";
	for (size_t i = 0; i < sorted.size() && i < 20; i++)
		std::cout << sorted[i] << " ";
	if (sorted.size() > 20)
		std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << _nSequence.size() << " elements with std::vector: "
	<< std::fixed << std::setprecision(6) << static_cast<double>(vectTime.count()) << " seconds" << std::endl;
	std::cout << "Time to process a range of " << _nSequence.size() << " elements with std::deque: "
	<< static_cast<double>(dequeTime.count()) << " seconds"<< std::endl;
	return ;
}
