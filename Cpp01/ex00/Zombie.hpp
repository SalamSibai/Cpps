

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name)
	{
		setName(name);
	}
	void	setName(std::string n);
	void	announce(void);
	~Zombie();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif