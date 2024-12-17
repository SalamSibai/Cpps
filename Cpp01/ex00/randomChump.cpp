
#include "Zombie.hpp"

//creates a zombie on the stack
void	randomChump(std::string name)
{
	Zombie random_chump;
	random_chump.setName(name);
	random_chump.announce();
}
