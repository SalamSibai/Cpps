
#include "Animal.h"

/* default constructor */
Animal::Animal()
{
	type = "Animal";
	std::cout << "animal constructor called" << std::endl ;
}

/* copy constructor */
Animal::Animal(const Animal &other)
{
	*this = other;
}

/* assignment operator */
Animal&	Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << type << "Making sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

/* destructor */
Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}
