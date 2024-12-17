
#include "Zombie.hpp"

Zombie::Zombie(void) {}

void	Zombie::setName(std::string n)
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