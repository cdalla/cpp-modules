#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	
		std::string _target;
		static const int	_exec = 137;
		static const int	_sign = 145;
		
	public:
	
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm();
		
		virtual void	execute(Bureaucrat const & executor) const;
		
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
};

#endif