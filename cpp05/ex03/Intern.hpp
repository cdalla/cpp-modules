#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include <exception>

class Intern
{
	public:
		
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);
		
		Intern	&operator=(Intern const & src);
		
		AForm*	makeForm(const std::string name, const std::string target);
		
	class FormNotExistException : public std::exception
	{
		public:
		
			virtual const char* what() const throw();
	};
		
};

#endif