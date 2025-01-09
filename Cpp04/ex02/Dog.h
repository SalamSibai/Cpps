
#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
	private:
		Brain	*brain;

	public:
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &rhs);
	~Dog();

	void	makeSound() const;
	void	printIdeas() const;
	std::string	getType() const;
};

#endif