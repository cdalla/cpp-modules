#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>



class Zombie
{
	public:
		
		Zombie(void);
		~Zombie(void);

		void	setName(std::string name);
		void	announce(void);

	private:

		std::string	_name;
		
};

#endif