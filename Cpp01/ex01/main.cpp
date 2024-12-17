
#include "Zombie.hpp"

int	main()
{
	Zombie *z = NULL;

	z = z->zombieHorde(5, "zombies");

	for (int i = 0; i < 5; i++)
	{
		z[i].announce();
	}
	delete[] z;

	return (0);
}
