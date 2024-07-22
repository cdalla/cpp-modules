#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	public:
		
		Zombie(std::string name);
		~Zombie(void);

	private:

		std::string	_name;
		
		void	announce(void);
};

#endif