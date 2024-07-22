#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <set>
# include <string>
# include <iostream>
# include <exception>
# include <climits>
# include <utility>
# include <algorithm>
# include <chrono>
# include <iomanip>

class PmergeMe
{
	private:
	
		std::vector<int>	_jacobsthalNumVect;
		std::deque<int>		_jacobsthalNumDeque;	
		std::vector<int>	_nSequence;
		std::deque<int>		_nDeSequence;
		int					_maxValue;
	
	public:
	
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &src);

		PmergeMe &operator=(PmergeMe const &src);
		
		void	makeJacobsthalSequence(void);
		void	sort(int argc, char *argv[]);
		void	parseInput(int argc, char *argv[]);
		void	makeSortPairV(std::vector<int>& sorted, std::vector<int>& toSort);
		void	insertMergeV(std::vector<int>& sorted, std::vector<int>& toSort);
		void	makeSortPairD(std::deque<int>& sorted, std::deque<int>& toSort);
		void	insertMergeD(std::deque<int>& sorted, std::deque<int>& toSort);
		void	printResult(std::chrono::duration<double> vectTime, std::chrono::duration<double> dequeTime, std::vector<int>& sorted);
		
};

#endif