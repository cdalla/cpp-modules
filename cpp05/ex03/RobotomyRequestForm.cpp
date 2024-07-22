#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
	
	_target = "none";
	
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", _sign, _exec), _target(target)
{
	
	std::cout << "RobotomyRequestForm constructor with parameters called" << std::endl;
	
	return ;
}	

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	
	*this = src;
	
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	
	return ;
}
		
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	
	this->_target = src._target;
	
	return *this;	
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkRequirements(executor);
	
	std::cout << "DRILLdrilliiiingDudurilling" << std::endl;
	
	std::srand(time(NULL));
	if ((std::rand() % 2) == 0) //using the computer internal clock to randomize the seed, so it will be different at every call of the program
		std::cout << this->_target << " has been robotomized!!!" << std::endl;
	else
		std::cout << "Robotomization failed on " << this->_target << std::endl;
		
	return ;	
}