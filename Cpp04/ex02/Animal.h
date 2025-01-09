

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal &rhs);
	virtual ~Animal();

	virtual void			makeSound(void) const = 0;
	virtual std::string		getType(void) const = 0;
};

#endif