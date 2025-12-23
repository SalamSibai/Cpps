
#ifndef	DIAMONDTRAP_H
#define	DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

/// @brief	This class implements diamond inheritance, which ensures
///			that only one copy of the parent class exists. Since both
///			parents of DiamondTrap inherit from the same parent "ClapTrap",
///			setting these classes to virtually inherit from the base ensures
///			that only one copy of ClapTrap will exist. This also means there wont
///			be any data sharing between the different classes. Values must be assigned
///			to the parent's protected attributes since there won't be copies of 
///			those variables in the two virtual parents. Only methods will be inherited
///			by DiamondTrap

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& rhs);
	~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();

private:
	std::string name;
};

#endif
