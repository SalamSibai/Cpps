
#include "Zombie.hpp"

Zombie::Zombie(void) {}

void	Zombie::setName(const std::string& n)
{
	this->_name = n;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dying." << std::endl;
}

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* zombies = new Zombie[N];


	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}

	return (zombies);
}