
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

		void			makeSound(void) const;
		std::string		getType(void) const;
};

#endif