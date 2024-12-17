
#include "Weapon.h"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType()
{
	return (type);
}

Weapon::~Weapon()
{

}