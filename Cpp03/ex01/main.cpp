
#include "ScavTrap.h"

int main()
{
	ScavTrap c("robot");

	
	ScavTrap b;

	ScavTrap d(c);
	c.attack("human");
	c.guardGate();
	c.takeDamage(100);
	// c.beRepaired(10);
	c.attack("human");
	b = c;
	b.attack("sd");
}