


#ifndef	FIXED_H
#define	FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int 	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);

		Fixed(const int		);		//converts const int to a fixed point value
		Fixed(const float	);		//converts const float to a fixed point value

		float	toFloat(void) const; // const here protects all member variables
		int		toInt(void)	const;

		Fixed& operator=(const Fixed& num);
		~Fixed();

///////////////////////////////////////////////////////////////////////////////
//							Comparision operators							 //
///////////////////////////////////////////////////////////////////////////////

		bool operator<(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);

///////////////////////////////////////////////////////////////////////////////
//							arthmetic operators								 //
///////////////////////////////////////////////////////////////////////////////

		Fixed operator+(const Fixed& rhs);
		Fixed operator-(const Fixed& rhs);
		Fixed operator*(const Fixed& rhs);
		Fixed operator/(const Fixed& rhs);

///////////////////////////////////////////////////////////////////////////////
//							increments and decrements						 //
///////////////////////////////////////////////////////////////////////////////

		void	operator++();
		void	operator--();
	//returning a reference allows the use of the previous value, 
	//then the decrementing or incerementing of the number
		Fixed&	operator++(int num);
		Fixed&	operator--(int num);

///////////////////////////////////////////////////////////////////////////////
//									min and max								 //
///////////////////////////////////////////////////////////////////////////////

		static Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& min(Fixed& num1, Fixed& num2);

		static Fixed& max(Fixed& num1, Fixed& num2);
		static Fixed& max(const Fixed& num1, const Fixed& num2);


		int 	getRawBits(void) const;
		void	setRawBits(const int raw);
};


/*An overload of the insertion («) operator that inserts a
	floating-point representation of the fixed-point number
	into the output stream object passed as parameter.*/
	
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif