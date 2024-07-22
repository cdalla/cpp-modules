#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

	private:

		Brain* _dogBrain;

	public:

		Dog();
		Dog(Dog const & src);
		virtual ~Dog();

		Dog & operator=(Dog const & src);

		virtual void makeSound(void) const;
		virtual void explainIdeas(void) const;

};

#endif