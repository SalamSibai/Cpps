


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

		Fixed(const int		);		//converts it to a fixed point value
		Fixed(const float	);		//converts const float to a fixed point value

		float	toFloat(void) const; // const here protects all member variables
		int		toInt(void)	const;


		Fixed& operator=(const Fixed& num);
		~Fixed();
		int 	getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif

/*An overload of the insertion («) operator that inserts a floating-point representation
	of the fixed-point number into the output stream object passed as parameter.*/
	
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
