
#include "WrongAnimal.h"

/* default constructor */
WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal constructor called." << std::endl;
}

/* copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal	&other)
{
	*this = other;
}

/* assignment operator */
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << type << "Wrong Animal making sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

/* destructor */
WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal Destructor called." << std::endl;
}