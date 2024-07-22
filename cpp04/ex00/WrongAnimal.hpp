#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal
{
	protected:

		std::string _type;

	public:

		WrongAnimal();					//default constructor
		WrongAnimal(WrongAnimal const & src);		//copy constructor
		virtual ~WrongAnimal(void);

		WrongAnimal & operator=(WrongAnimal const & src);

		void 			makeSound(void) const;
		std::string		getType(void) const;
};

#endif