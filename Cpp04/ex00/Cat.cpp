
#include "Cat.h"

Cat::Cat() 
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
};

Cat::Cat(const Cat &other)
{
	*this = other; 
}

Cat& Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound()	const
{
	std::cout << "MeeeyaaaaaaaaaWWW!" << std::endl;
}
