

#ifndef	FIXED_H
#define	FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int 	fractional_bit = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& num);
		~Fixed();
		int 	getRawBits(void) const;
		void	setRawBits(const int raw);

};

#endif