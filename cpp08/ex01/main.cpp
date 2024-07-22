#include "Span.hpp"

int main(void)
{
	//NORMAL
	std::cout << "NORMAL BEHAVIOUR" << std::endl;
	try
	{
		Span mySpan(5);
		
		mySpan.addNumber(6);
		mySpan.addNumber(3);
		mySpan.addNumber(17);
		mySpan.addNumber(9);
		mySpan.addNumber(11);
		
		Span copySpan(mySpan);
		
		std::cout << "Max span is: " << mySpan.longestSpan() << std::endl;
		std::cout << "Min span is: " << mySpan.shortestSpan() << std::endl;
		std::cout << "Max span in copy is: " << copySpan.longestSpan() << std::endl;
		std::cout << "Min span in copy is: " << copySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	//RANDOM
	std::cout << "\n100000 RANDOM NUMBERS" << std::endl;
	try
	{
		Span mySpan(100000);
	
		mySpan.addRandomNumbers(100000);
		
		std::cout << "Max span is: " << mySpan.longestSpan() << std::endl;
		std::cout << "Min span is: " << mySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	//RANGE
	std::cout << "\nADD A RANGE" << std::endl;
	try
	{
		Span mySpan(100);
	
		std::vector<int> range{1,2,3,4,5,6,10};
		mySpan.addRange(range.begin(), range.end());
		
		std::cout << "Max span is: " << mySpan.longestSpan() << std::endl;
		std::cout << "Min span is: " << mySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	//FULL SPAN EXCEPTION
	std::cout << "\nFULL SPAN EXCEPTION" << std::endl;
	try
	{
		Span mySpan(5);
	
		mySpan.addNumber(6);
		mySpan.addNumber(3);
		mySpan.addNumber(17);
		mySpan.addNumber(9);
		mySpan.addNumber(11);
		mySpan.addNumber(1);
		
		std::cout << "Max span is: " << mySpan.longestSpan() << std::endl;
		std::cout << "Min span is: " << mySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	//EMPTY SPAN EXCEPTION
	std::cout << "\nEMPTY SPAN EXCEPTION MAX" << std::endl;
	try
	{
		Span mySpan(5);
	
		mySpan.addNumber(6);
		
		std::cout << "Max span is: " << mySpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	//EMPTY SPAN EXCEPTION
	std::cout << "\nEMPTY SPAN EXCEPTION MIN" << std::endl;
	try
	{
		Span mySpan(5);
		
		std::cout << "Min span is: " << mySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
