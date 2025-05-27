
#include "Dog.h"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
};

Dog::Dog(const Dog &other) : Animal()
{
	*this = other; 
}

Dog& Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "BARK BARK BARK!" << std::endl;
}
