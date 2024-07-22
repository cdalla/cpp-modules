#include "Form.hpp"

//CONSTRUCTORS DESTRUCTOR

Form::Form() : _name("NoName"), _signed(false), _sign(150), _exec(150)
{
	std::cout << "Form default constructor called" << std::endl;

	return ;
}

Form::Form(std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec)
{
	std::cout << "Form constructor with parameters called" << std::endl;

	if (_sign < 1 || _exec < 1)
		throw GradeTooHighException();
	else if (_sign > 150 || _exec > 150)
		throw GradeTooLowException();
	
	return ;
}

Form::Form(Form const & src) : _name(src.getName()), _sign(src.getSign()), _exec(src.getExec())
{
	*this = src;

	std::cout << "Copy constructor called" << std::endl;

	return ;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;

	return ;
}

//OPERATORS

Form & Form::operator=(Form const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_signed = false;
	
	const_cast<std::string&>(_name) = src.getName();
	const_cast<int&>(_sign) = src.getSign();
	const_cast<int&>(_exec) = src.getExec();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Form const & src)
{
	o << src.getName() << " can be signed by grade "<< src.getSign() << ", can be execute by grade " << src.getExec();
	o << ",\ndocument is ";
	if (src.isSigned())
		o << "signed";
	else
		o << "not signed";

	return o;
}

//GETTERS

std::string Form::getName(void) const
{
	return this->_name;
}

bool		Form::isSigned(void) const
{
	return this->_signed;
}

int			Form::getSign(void) const
{
	return this->_sign;
}

int			Form::getExec(void) const
{
	return this->_exec;
}

//FORM FUNCTIONS

void		Form::beSigned(Bureaucrat &param)
{
	if (param.getGrade() > _sign)
	{
		throw GradeTooLowException();
	}
	this->_signed = true;

	return ;
}

