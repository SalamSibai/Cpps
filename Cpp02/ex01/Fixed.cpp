
#include "Fixed.h"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * 			shifting the decimal point 8 to the right
 * 
 * @param i the value of the fixed point in int 
 * 
 */
Fixed::Fixed(const int	i)
{
	fixed_point = i * (1 << fractional_bits);
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * 			TRUNCATES the value of i to fit into the fixed point
 * 			if a cast is used, it would more correctly represent
 * 			the number.
 * 
 * @param i the value of the fixed point in int 	
 */
Fixed::Fixed(const float i)
{
	fixed_point = (i * (1 << fractional_bits));
}

Fixed&	Fixed::operator=(const Fixed &rhs)
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

float	Fixed::toFloat() const
{
	return (fixed_point / 256.0f);
}

int	Fixed::toInt() const
{
	return (fixed_point / 256);
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
