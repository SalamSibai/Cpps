
#include "Cat.h"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
};

Cat::Cat(const Cat &other) : Animal()
{
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		delete	brain;
		brain = new Brain(*rhs.brain);
		type = rhs.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete	brain;
}

void	Cat::makeSound() const
{
	std::cout << "MeeeyaaaaaaaaaWWW!" << std::endl;
} 

void	Cat::printIdeas() const
{
	for(int i = 0; i < 100; i++)
		std::cout << brain->getIdeas()[i] << std::endl;
}

std::string Cat::getType() const
{
	return (type);
}
