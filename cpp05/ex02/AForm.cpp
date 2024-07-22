#include "AForm.hpp"

//CONSTRUCTOR DESTRUCTOR

AForm::AForm() : _name("NoName"), _signed(false), _sign(150), _exec(150)
{
	std::cout << "Form default constructor called" << std::endl;

	return ;
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec)
{
	std::cout << "Form constructor with parameters called" << std::endl;

	if (_sign < 1 || _exec < 1)
		throw GradeTooHighException();
	else if (_sign > 150 || _exec > 150)
		throw GradeTooLowException();
	
	return ;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _sign(src.getSign()), _exec(src.getExec())
{
	*this = src;

	std::cout << "Copy constructor called" << std::endl;

	return ;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;

	return ;
}

//OPERATORS

AForm & AForm::operator=(AForm const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_signed = false;
	
	const_cast<std::string&>(_name) = src.getName();
	const_cast<int&>(_sign) = src.getSign();
	const_cast<int&>(_exec) = src.getExec();
	
	return *this;
}

std::ostream & operator<<(std::ostream & o, AForm const & src)
{
	o << src.getName() << " can be signed by grade "<< src.getSign() << ", can be execute by grade " << src.getExec();
	o << ",\ndocument is ";
	if (src.isSigned())
		o << "signed";
	else
		o << "not signed";

	return o;
}

//GETTER

std::string AForm::getName(void) const
{
	return this->_name;
}

bool		AForm::isSigned(void) const
{
	return this->_signed;
}

int			AForm::getSign(void) const
{
	return this->_sign;
}

int			AForm::getExec(void) const
{
	return this->_exec;
}

//FORM FUNCTIONS

void		AForm::checkRequirements(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getExec())
		throw GradeTooHighException();
		
	return ;
}

void		AForm::beSigned(Bureaucrat &param)
{
	if (param.getGrade() > _sign)
	{
		throw GradeTooLowException();
	}
	this->_signed = true;

	return ;
}

