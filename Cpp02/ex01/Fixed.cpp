
#include "Fixed.h"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed& 		Fixed::operator=(const Fixed &rhs)
{
	this->fixed_point = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}



