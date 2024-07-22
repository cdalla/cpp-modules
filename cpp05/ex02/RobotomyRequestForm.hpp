#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	
		std::string _target;
		static const int	_sign = 72;
		static const int	_exec = 45;
		
	public:
			
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const & executor) const;
		
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
};

#endif