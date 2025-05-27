

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	name = "ScavTrap";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 50;

	std::cout << "ScavTrap: default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	name = _name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 50;

	std::cout << "ScavTrap: constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap()
{
	*this = other;
	std::cout << "ScavTrap: copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	name = rhs.name;
	hit_points = rhs.hit_points;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	std::cout << "ScavTrap: assignment operator called." << std::endl; 

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: distructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_points > 0 && energy_points > 0)
		std::cout << "ScavTrap: " << name << " attacked " << target << " !" << std::endl;
	else
	{
		std::cout << "ScavTrap: ";
		if (hit_points == 0 && energy_points == 0)
			std::cout << "out of hitpoints and energy points, cant attack " << target << ", lucky " << target << std::endl;
		else if (hit_points == 0)
			std::cout << "no hitpoints, cant attack " << target << ", lucky " << target << std::endl;
		else
			std::cout << "no energy points, cant attack " << target << ", lucky " << target << std::endl;
	}

}

void	ScavTrap::guardGate()
{	
	std::cout << "ScavTrap: is in gatekeeping mode now." << std::endl;
}
