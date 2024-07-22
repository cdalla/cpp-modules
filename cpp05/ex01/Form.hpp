#ifndef FORM_H
# define FORM_H

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:

		const std::string	_name;
		bool 				_signed;
		const int			_sign;
		const int			_exec;

	
	public:

		Form();
		Form(std::string name, int sign, int exec);
		Form(Form const & src);
		~Form();

		Form & operator=(Form const & src);
		std::string getName() const;
		bool		isSigned() const;
		int			getSign() const;
		int			getExec() const;
		void		beSigned(Bureaucrat  &param);

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char* what() const throw()
				{
					return "Grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char* what() const throw()
				{
					return "Grade too low";
				}
		};

};

std::ostream & operator<<(std::ostream & o, Form const & src);

#endif