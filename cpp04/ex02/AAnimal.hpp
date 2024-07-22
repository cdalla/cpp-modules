#ifndef AANIMAL_H
# define AANIMAL_H

#include <string>

class AAnimal
{
	protected:

		std::string _type;

	public:

		AAnimal();							//default constructor
		AAnimal(AAnimal const & src);		//copy constructor
		virtual ~AAnimal(void);

		AAnimal & operator=(AAnimal const & src);

		virtual void 	makeSound(void) const = 0;
		std::string		getType(void) const;
		virtual void	explainIdeas(void) const = 0;
};

#endif