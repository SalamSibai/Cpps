#include <iostream>
#include "Weapon.h"

#ifndef HUMANB_H
#define	HUMANB_H

class HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &Weapon);
		void	attack();
		~HumanB();

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif