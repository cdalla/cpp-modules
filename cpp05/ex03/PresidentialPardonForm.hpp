#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	
		std::string	_target;
		static const int	_sign = 25;
		static const int	_exec = 5;
		
	public:
	
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual	~PresidentialPardonForm();

		virtual void	execute(Bureaucrat const & executor) const;
		
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
};

#endif