#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal
{
	protected:

		std::string _type;

	public:

		Animal();					//default constructor
		Animal(Animal const & src);		//copy constructor
		virtual ~Animal(void);

		Animal & operator=(Animal const & src);

		virtual void 	makeSound(void) const;
		std::string		getType(void) const;
};

#endif