
#ifndef	FRAGTRAP_H
#define	FRAGTRAP_H

#include "ClapTrap.h"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void attack(const std::string& target);
	void guardGate();
	void highFivesGuys(void);
};

#endif