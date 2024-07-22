#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"



int	main(void)
{
	std::cout << "NORMAL BEHAVIOUR\n" << std::endl;
	try
	{
		Bureaucrat				Yoyo("yoyo",1);
		ShrubberyCreationForm	tree("awesome_tree");
		RobotomyRequestForm		brother("my brother");
		PresidentialPardonForm	pirate("Jackie The Sparrow");
	
		std::cout << "\n" << std::endl;
	
		Yoyo.signForm(tree);
		Yoyo.executeForm(tree);
		
		std::cout << "\n" << std::endl;
		
		Yoyo.signForm(brother);
		Yoyo.executeForm(brother);
		
		std::cout << "\n" << std::endl;
		
		Yoyo.signForm(pirate);
		Yoyo.executeForm(pirate);
		
		std::cout << "\n" << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
	std::cout << "\nGRADE TOO LOW TO EXECUTE EXCEPTION\n" << std::endl;
	try
	{
		Bureaucrat				Yoyo("yoyo",140);
		ShrubberyCreationForm	test("home");
	
		std::cout << "\n" << std::endl;
		
		Yoyo.signForm(test);
		Yoyo.executeForm(test);
		
		std::cout << "\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nGRADE TOO LOW TO SIGN EXCEPTION\n" << std::endl;
	try
	{
		Bureaucrat				Yoyo("yoyo",26);
		PresidentialPardonForm	test("home");
	
		std::cout << "\n" << std::endl;
		
		Yoyo.signForm(test);
		Yoyo.executeForm(test);
		
		std::cout << "\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nNOT SIGNED EXCEPTION\n" << std::endl;
	try
	{
		Bureaucrat				Yoyo("yoyo",1);
		RobotomyRequestForm		test("home");
	
		std::cout << "\n" << std::endl;
	
		Yoyo.executeForm(test);
		
		std::cout << "\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}