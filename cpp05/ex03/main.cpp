#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"



int	main(void)
{
	std::cout << "ROBOTOMY REQUEST\n" << std::endl;
	try
	{
		Bureaucrat	Bur("Ciccio", 1);
		Intern	deNiro;
		AForm	*noName;
		
		std::cout << "\n";
		
		noName = deNiro.makeForm("robotomy request", "Bender");
		Bur.signForm(*noName);
		Bur.executeForm(*noName);
		
		delete noName;	
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nPRESIDENTIAL REQUEST\n" << std::endl;
	try
	{
		Intern	deNiro;
		AForm	*noName;
		
		std::cout << "\n";
		
		noName = deNiro.makeForm("presidential pardon request", "Lulu");
		
		delete noName;	
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nSHRUBBERY REQUEST\n" << std::endl;
	try
	{
		Intern	deNiro;
		AForm	*noName;
		
		std::cout << "\n";
		
		noName = deNiro.makeForm("shrubbery creation request", "apple_tree");
		
		delete noName;	
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nREQUEST NOT EXIST EXCEPTION\n" << std::endl;
	try
	{
		Intern	deNiro;
		AForm	*noName;
		
		std::cout << "\n";
		
		noName = deNiro.makeForm("request", "Bender");
		
		delete noName;	
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
	return 0;
}