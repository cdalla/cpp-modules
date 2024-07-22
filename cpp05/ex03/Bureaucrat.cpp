#include "Bureaucrat.hpp"
#include "AForm.hpp"

//CONSTRUCTORS AND DESTRUCTORS

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;

	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Constructor with parameters called" << std::endl;

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;

	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) 
{
	*this = src;

	std::cout << "Bureaucrat Copy constructor called" << std::endl;

	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;

	return ;
}

//OPERATORS 

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_grade = src.getGrade();
	
	//this does not work because it is a const
	// this->_name = src.getName();
	
	const_cast<std::string&>(_name) = src.getName();

	return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();

	return o;
}

//GETTERS

std::string		Bureaucrat::getName(void) const
{
	return this->_name;
}

int		Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

//GRADE MODIFICATION FUNCTIONS

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Incrementing Bureaucrat " << this->getName() << " grade..." << std::endl;
	this->_grade = this->getGrade() - 1;
	
	if (this->_grade < 1)
		throw GradeTooHighException();

	std::cout << "Bureaucrat " << this->getName() << " new grade is " << this->getGrade() << std::endl;

	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Decrementing Bureaucrat " << this->getName() << " grade..." << std::endl;
	this->_grade = this->getGrade() + 1;

	if (this->_grade > 150)
		throw GradeTooLowException();
	
	std::cout << "Bureaucrat " << this->getName() << " new grade is " << this->getGrade() << std::endl;

	return ;
}

//EXCEPTIONS

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

//BUREAUCRAT FUNCTIONS

void	Bureaucrat::signForm(AForm &param)
{	
	try
	{
		param.beSigned(*this);
		std::cout << this->getName() << " signed " << param.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << param.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	
	return ;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " could not execute " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	
}