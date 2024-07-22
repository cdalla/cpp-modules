#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:

		Brain*	_catBrain;

	public:

		Cat();
		Cat(Cat const & src);
		virtual ~Cat();

		Cat & operator=(Cat const & src);

		virtual void makeSound(void) const;
		virtual void explainIdeas(void) const;
		
};

#endif