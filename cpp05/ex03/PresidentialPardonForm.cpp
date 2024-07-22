#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
	
	_target = "none";
	
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", _sign, _exec), _target(target)
{
	std::cout << "PresidentialPardonForm constructor with parameters called" << std::endl;
	
	return ;
}	

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	
	*this = src;
	
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	
	return ;
}
		
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	
	this->_target = src._target;

	return *this;	
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkRequirements(executor);
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	
	return ;
}