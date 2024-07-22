#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element of Mutant stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Top element of Mutant stack after pop(): " << mstack.top() << std::endl;
	std::cout << "Mutant stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	mstack.pop();
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	//mstack.pop();
	//mstack.push(0);
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack); //create a stack object from a Mutant stack object 
	
	//LIST
	std::cout << "\nLIST" << std::endl;
	
	std::list<int> mList;
	mList.push_back(5);
	mList.push_back(17);
	std::cout << "Top element of list: " << mList.back() << std::endl;
	mList.pop_back();
	std::cout << "Top element of list after pop_back(): " << mList.back() << std::endl;
	std::cout << "List size: " << mList.size() << std::endl;
	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	mList.push_back(0);
	
	mList.pop_back();
	std::list<int>::iterator lIt = mList.begin();
	std::list<int>::iterator lIte = mList.end();
	++lIt;
	--lIt;
	//mList.pop_back();
	//mList.push_back(0);
	while (lIt != lIte)
	{
		std::cout << *lIt << std::endl;
		++lIt;
	}

	//DEQUE
	std::cout << "\nDEQUE" << std::endl;
	
	std::deque<int> mDeque;
	mDeque.push_back(5);
	mDeque.push_back(17);
	std::cout << "Top element of deque: " << mDeque.back() << std::endl;
	mDeque.pop_back();
	std::cout << "Top element of deque after pop_back(): " << mDeque.back() << std::endl;
	std::cout << "List size: " << mDeque.size() << std::endl;
	mDeque.push_back(3);
	mDeque.push_back(5);
	mDeque.push_back(737);
	mDeque.push_back(0);
	
	mDeque.pop_back();
	std::deque<int>::iterator dIt = mDeque.begin();
	std::deque<int>::iterator dIte = mDeque.end();
	++dIt;
	--dIt;
	//mDeque.pop_back();
	//mDeque.push_back(0);
	while (dIt != dIte)
	{
		std::cout << *dIt << std::endl;
		++dIt;
	}
	
	
	//REVERSE ITERATOR
	std::cout << "\nReverse iterator on copy MutantStack\n" << std::endl;
	MutantStack<int> revStack(mstack);
	
	MutantStack<int>::reverse_iterator rIt = revStack.rbegin();
	MutantStack<int>::reverse_iterator rIte = revStack.rend();
	++rIt;
	--rIt;
	while (rIt != rIte)
	{
		std::cout << *rIt << std::endl;
		++rIt;
	}
	
	return 0;
}