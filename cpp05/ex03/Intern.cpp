#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	
	return ;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	
	std::cout << "Intern copy constructor called" << std::endl;
	
	return ;
}

Intern & Intern::operator=(Intern const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

const char* Intern::FormNotExistException::what() const throw()
{
	return ("This form type does not exist\n");
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
	std::string types[3] = {"presidential pardon request", "robotomy request", "shrubbery creation request"};
	int	i;
	
	for (i = 0; i <= 2; i++)
	{
		if (types[i] == formName)
			break ;
	}
	std::cout << "Intern creates " << formName << "\n" <<std::endl;
	
	try
	{
		switch(i)
		{
			case 0:
				return new PresidentialPardonForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new ShrubberyCreationForm(target);
			default:
				throw FormNotExistException();
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return nullptr;
}