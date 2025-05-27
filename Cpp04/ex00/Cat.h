
#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal
{
	public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &rhs);
	~Cat();

	void	makeSound() const;
};

#endif