
#include "Fixed.h"

Fixed::Fixed()
{
	std::cout << "default constructor called\n";
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "copy constructor called\n";
	*this = fixed;
}

Fixed& 		Fixed::operator=(const Fixed &rhs)
{
	std::cout << "assignment operator called\n";
	this->fixed_point = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getter called\n";
	return (this->fixed_point);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setter called\n";
	this->fixed_point = raw;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}



