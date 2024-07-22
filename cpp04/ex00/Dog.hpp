#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	public:

		Dog();
		Dog(Dog const & src);
		virtual ~Dog();

		Dog & operator=(Dog const & src);

		void virtual makeSound(void) const;

};

#endif