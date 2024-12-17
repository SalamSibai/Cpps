
#include <iostream>

#ifndef WEAPON_H
#define	WEAPON_H

class Weapon
{
	public:
		Weapon(){};
		Weapon(std::string type);
		std::string	getType();
		void		setType(std::string type);
		~Weapon();

	private:
		std::string type;
};

#endif