
#include "Zombie.hpp"

/**
 * @brief This creates a zombie object on the heap
 * 
 * @param name the name of the zombie
 * @return Zombie* returns a new instance of the zombie
 */
Zombie* newZombie(std::string name)
{
	Zombie* new_zombie = new Zombie(name);
	return (new_zombie);
}
