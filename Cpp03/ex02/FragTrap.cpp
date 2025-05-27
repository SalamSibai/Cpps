


#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	name = "FragTrap";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;

	std::cout << "#FragTrap: default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	name = _name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;

	std::cout << "#FragTrap: constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap()
{
	*this = other;
	std::cout << "#FragTrap: copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	name = rhs.name;
	hit_points = rhs.hit_points;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	std::cout << "#FragTrap: assignment operator called." << std::endl; 

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "#FragTrap: distructor called." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hit_points > 0 && energy_points > 0)
		std::cout << "#FragTrap: " << name << " attacked " << target << " !" << std::endl;
	else
	{
		std::cout << "#FragTrap: ";
		if (hit_points == 0 && energy_points == 0)
			std::cout << "out of hitpoints and energy points, cant attack " << target << ", lucky " << target << std::endl;
		else if (hit_points == 0)
			std::cout << "no hitpoints, cant attack " << target << ", lucky " << target << std::endl;
		else
			std::cout << "no energy points, cant attack " << target << ", lucky " << target << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "#FragTrap: " << name << " - HIGH FIVE GUYS!!" << std::endl;
}
