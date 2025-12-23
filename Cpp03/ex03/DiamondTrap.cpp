



#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
: ClapTrap("DiamondTrap_clap_name"),
FragTrap("DiamondTrap"),
ScavTrap("DiamondTrap")
{
    name = "DiamondTrap";
    hit_points     = 100; // FragTrap
    energy_points  = 50;  // ScavTrap
    attack_damage  = 30;  // FragTrap
}

DiamondTrap::DiamondTrap(std::string _name) 
    : name(_name), 
    ClapTrap("DiamondTrap_clap_name"),
    FragTrap("DiamondTrap"),
    ScavTrap("DiamondTrap")
{
    hit_points     = 100; // FragTrap
    energy_points  = 50;  // ScavTrap
    attack_damage  = 30;  // FragTrap
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :  
        ClapTrap("DiamondTrap_clap_name"),
        FragTrap("DiamondTrap"),
        ScavTrap("DiamondTrap")
{
    *this = other;
    std::cout << "DiamondTrap: copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    name = rhs.name;
	hit_points = rhs.hit_points;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	std::cout << "ScavTrap: assignment operator called." << std::endl; 

	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "#DiamondTrap: destructor called." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am the diamond trap " << name;
    std::cout << "My claptrap name is " << ClapTrap::name;
}