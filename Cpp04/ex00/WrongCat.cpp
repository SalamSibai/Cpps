
#include "WrongCat.h"


#include "Cat.h"

WrongCat::WrongCat() 
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
};

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other; 
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound()	const
{
	std::cout << "MeeeyaaaaaaaaaWWW!" << std::endl;
}
