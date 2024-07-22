#include "Bureaucrat.hpp"

int  main(void)
{
	std::cout << "Normal behaviour\n" << std::endl;
	try
	{
		Bureaucrat a;
		Bureaucrat b("Gianni", 1);
		Bureaucrat c(b);
		
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		
		b.decrementGrade();
		a.incrementGrade();
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nIncrement exception\n" << std::endl;
	try
	{
		Bureaucrat b("Gianni", 1);
		
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nDecrement exception\n" << std::endl; 
	try
	{
		Bureaucrat b("Gianni", 150);
		
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nLow grade creation exception\n" << std::endl; 
	try
	{
		Bureaucrat b("Gianni", 151);
		
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nHigh grade creation exception\n" << std::endl; 
		try
	{
		Bureaucrat b("Gianni", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
