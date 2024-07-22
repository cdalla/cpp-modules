#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	public:

		Cat();
		Cat(Cat const & src);
		virtual ~Cat();

		Cat & operator=(Cat const & src);

		virtual void makeSound(void) const;
		
};

#endif