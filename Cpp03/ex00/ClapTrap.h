
#ifndef	CLAPTRAP_H
#define	CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:
		std::string 	name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amout);
		void	beRepaired(unsigned int amout);
};

#endif