



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

DiamondTrap::~DiamondTrap()
{
	std::cout << "#DiamondTrap: distructor called." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}