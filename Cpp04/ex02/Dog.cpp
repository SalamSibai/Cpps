
#include "Dog.h"

Dog::Dog() : Animal()
{
	brain = new	Brain();
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
};

Dog::Dog(const Dog &other) : Animal()
{
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		delete	brain;
		brain = new Brain(*rhs.brain);
		type = rhs.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete	brain;
}

void	Dog::makeSound()	const
{
	std::cout << "BARK BARK BARK!" << std::endl;
}

void	Dog::printIdeas() const
{
	for(int i = 0; i < 100; i++)
		std::cout << brain->getIdeas()[i] << std::endl;
}

std::string Dog::getType() const
{
	return (type);
}
