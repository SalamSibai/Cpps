
#include "Fixed.h"


///////////////////////////////////////////////////////////////////////////////
//							Constructors & Destructor						 //
///////////////////////////////////////////////////////////////////////////////

Fixed::Fixed() : fixed_point(0) {}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed &rhs)
{
	this->fixed_point = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
//							User defined constructors						 //
///////////////////////////////////////////////////////////////////////////////

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
	fixed_point = roundf(i * (1 << fractional_bits));
}

///////////////////////////////////////////////////////////////////////////////
//									getters									 //
///////////////////////////////////////////////////////////////////////////////

int	Fixed::getRawBits() const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
}

///////////////////////////////////////////////////////////////////////////////
//									converters								 //
///////////////////////////////////////////////////////////////////////////////

float	Fixed::toFloat() const
{
	//return (fixed_point / 256.0f);
	return fixed_point / (1.0f * (1 << fractional_bits));
}

int	Fixed::toInt() const
{
	//return (fixed_point / 256);
	return fixed_point / (1.0f * (1 << fractional_bits));
}

///////////////////////////////////////////////////////////////////////////////
//							Comparision operators							 //
///////////////////////////////////////////////////////////////////////////////

//less than operator
bool Fixed::operator<(const Fixed& other) const
{
	return (fixed_point < other.fixed_point);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (other.fixed_point < fixed_point);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (fixed_point == other.fixed_point ||
			fixed_point > other.fixed_point);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (fixed_point == other.fixed_point ||
			fixed_point < other.fixed_point);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (fixed_point != other.fixed_point);
}

///////////////////////////////////////////////////////////////////////////////
//							increments and decrements						 //
///////////////////////////////////////////////////////////////////////////////

Fixed&	Fixed::operator++()
{
	++fixed_point;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--fixed_point;
	return (*this);
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);  // Save the current state
    ++fixed_point;      // Increment the value
    return temp;        // Return the saved state
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--fixed_point;
	return (temp);
}

///////////////////////////////////////////////////////////////////////////////
//							arthmetic operators								 //
///////////////////////////////////////////////////////////////////////////////

Fixed Fixed::operator+(const Fixed& rhs)
{
	Fixed result;
	result.fixed_point = fixed_point + rhs.fixed_point;
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs)
{
	Fixed result;
	fixed_point = fixed_point - rhs.fixed_point;
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) 
{
	Fixed result;
	result.fixed_point = (fixed_point * rhs.fixed_point) >> fractional_bits;
	return result;
}


Fixed Fixed::operator/(const Fixed& rhs)
{
	Fixed result;
	if (rhs.fixed_point != 0)
		result.fixed_point = (fixed_point << fractional_bits) / rhs.fixed_point;
	return result;
}

///////////////////////////////////////////////////////////////////////////////
//									min and max								 //
///////////////////////////////////////////////////////////////////////////////

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1.fixed_point > num2.fixed_point)
		return num2;
	return num1;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1.fixed_point > num2.fixed_point)
		return num2;
	return num1;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1.fixed_point < num2.fixed_point)
		return num2;
	return num1;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1.fixed_point < num2.fixed_point) 
		return num2;
	return num1;
}


///////////////////////////////////////////////////////////////////////////////
//							non-member functions							 //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
