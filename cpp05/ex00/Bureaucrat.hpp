#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(Bureaucrat const & src);
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();


		Bureaucrat & operator=(Bureaucrat const & src);
		std::string getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);


	class GradeTooHighException : public std::exception
	{
		public :
			
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			
			virtual const char* what() const throw();
	};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif