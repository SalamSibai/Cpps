

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
	void	setName(const std::string& n);
	void	announce(void);
	Zombie* zombieHorde(int N, std::string name );
	~Zombie();
};


#endif