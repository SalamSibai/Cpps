

#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap() : name("ClapTrap"),  hit_points(10), 
						energy_points(10), attack_damage(0) 
{
	std::cout << "default constructor called." << std::endl; 
}

ClapTrap::ClapTrap(std::string _name) 
						: name(_name),  hit_points(10), 
						energy_points(10), attack_damage(0) 
{
	std::cout << "default constructor (with name) called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "copy constructor called." << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	name = rhs.name;
	hit_points = rhs.hit_points;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	return	*this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "destructor called." << std::endl; 
}

void	ClapTrap::attack(const std::string& target)
{
	if (hit_points > 0 && energy_points > 0)
	{
		std::cout << name << " attacked " << target << "!" << std::endl;
		std::cout << "Target "<< target <<" was hit!" << std::endl;
		energy_points --;

		//call target's take damage function
	}
	else
	{
		if (hit_points == 0)
			std::cout << "no hitpoints, cant attack " << target << ", lucky " << target << std::endl;
		else if (energy_points == 0)
			std::cout << "no energy points, cant attack " << target << ", lucky " << target << std::endl;
		else
			std::cout << "out of hitpoints and energy points, cant attack " << target << ", lucky " << target << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points > 0 && energy_points > 0)
	{
		std::cout << name << " healed self by "<< amount <<" amount!" << std::endl;
		hit_points += amount;
		energy_points --;
	}
	else
	{
		if (hit_points == 0)
			std::cout << "no hitpoints, cant repair self. :(" << std::endl;
		else if (energy_points == 0)
			std::cout << "no energy points, cant repair self. :(" << std::endl;
		else
			std::cout << "out of hitpoints and energy points, cant repair self. :(" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
	
	std::cout << name << " has taken " << amount << " amount of damage!" << std::endl;
	std::cout << name << " has only " << hit_points << " left!" << std::endl;
}
