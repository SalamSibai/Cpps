
#include "ClapTrap.h"

int main()
{
	ClapTrap a("enemy");
	ClapTrap b("hitman");

	a.attack("hitman");
	a.beRepaired(10);
	a.takeDamage(30);

	ClapTrap o(a);
	o.attack("lol");
}