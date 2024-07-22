
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;

	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Constructor with parameters called" << std::endl;

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

	std::cout << "Copy constructor called" << std::endl;

	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;

	return ;
}

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

std::string		Bureaucrat::getName(void) const
{
	return this->_name;
}

int		Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

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

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}