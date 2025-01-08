
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &rhs);
	~Dog();

	void	makeSound() const;
};

#endif