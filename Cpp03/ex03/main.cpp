
#include "FragTrap.h"
#include "ScavTrap.h"

int main()
{
	FragTrap c("robot");
	ScavTrap g("fa");

	ScavTrap b;

	b =g;
	c.highFivesGuys();
	c.takeDamage(10);
	c.beRepaired(10);

	g.attack("human");
	g.takeDamage(10);
	g.beRepaired(10);
	g.attack("human");
	
	b.attack("human");
	b.takeDamage(10);
	b.beRepaired(10);
	b.attack("human");
}