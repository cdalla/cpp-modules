#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(WrongCat const & src);
		virtual ~WrongCat();

		WrongCat & operator=(WrongCat const & src);

		void makeSound(void) const;
		
};

#endif
