#ifndef FORM_H
# define FORM_H

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:

		const std::string	_name;
		bool 				_signed;
		const int			_sign;
		const int			_exec;

	
	public:

		AForm();
		AForm(std::string name, int sign, int exec);
		AForm(AForm const & src);
		virtual ~AForm();

		AForm & operator=(AForm const & src);
		
		std::string 	getName() const;
		bool			isSigned() const;
		int				getSign() const;
		int				getExec() const;
		void			checkRequirements(Bureaucrat const &param) const;
		void			beSigned(Bureaucrat  &param);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char* what() const throw()
				{
					return "Form grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char* what() const throw()
				{
					return "Form grade too low";
				}
		};
		
		class NotSignedException : public std::exception
		{
			public:

				virtual const char* what() const throw()
				{
					return "Form not signed";
				}
		};

};

std::ostream & operator<<(std::ostream & o, AForm const & src);

#endif