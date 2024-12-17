
#include "Zombie.hpp"

int	main()
{
	Zombie random_zombie("random");
	Zombie *actual_zombie = NULL;

	actual_zombie = newZombie("real");
	actual_zombie->announce();
	random_zombie.announce();
	delete (actual_zombie);
}
