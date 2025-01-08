
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &rhs);
	~Dog();

	void	setType(std::string type);
	void	makeSound() const;
};

#endif