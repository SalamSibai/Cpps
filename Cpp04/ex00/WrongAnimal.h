
#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal &rhs);
		~WrongAnimal();
};

#endif