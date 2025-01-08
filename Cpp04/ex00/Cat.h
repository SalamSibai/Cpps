
#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Cat : public Animal
{
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &rhs);
	~Cat();

	void	makeSound() const;
};

#endif