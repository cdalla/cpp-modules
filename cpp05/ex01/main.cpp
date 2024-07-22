#include "Bureaucrat.hpp"
#include "Form.hpp"

int  main(void)
{
	std::cout << "Normal behaviour\n" << std::endl;
	try
	{
		Bureaucrat Bur("Gianni", 1);
		Form form1;
		Form form2("Expenses", 75, 75);
	
		std::cout << Bur << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		form1 = form2;
		std::cout << form1 << std::endl;
		
		Bur.signForm(form1);
		//form1.beSigned(&Bur);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nForm high grade exception\n" << std::endl;
	try
	{
		Form form("Expenses", 0, 75);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nForm low grade exception\n" << std::endl;
	try
	{
		Form form("Expenses", 75, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nBureacrat low grade to sign exception\n" << std::endl;
	try
	{
		Bureaucrat Bur("Erman", 100);
		Form form("Expenses", 75, 75);
		
		Bur.signForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

