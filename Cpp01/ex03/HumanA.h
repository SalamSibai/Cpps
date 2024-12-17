#include <iostream>
#include "Weapon.h"


#ifndef HUMANA_H
#define	HUMANA_H

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();
		~HumanA();

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif