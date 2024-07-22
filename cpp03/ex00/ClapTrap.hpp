#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap
{
	private:
	
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		
		ClapTrap & operator=(ClapTrap const & src);

		std::string getName(void) const;
		int			getEnergy(void) const;
		int			getAttackDamage(void) const;
		int			getHitPoints(void) const;
		void		attack(const std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

};

#endif