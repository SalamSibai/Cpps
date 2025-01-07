/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:23 by ssibai            #+#    #+#             */
/*   Updated: 2025/01/07 10:52:25 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_H
#define	FIXED_H

#include <iostream>
#include <cmath>

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

		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

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

		Fixed&	operator++();
		Fixed&	operator--();
	//returning a reference allows the use of the previous value, 
	//then the decrementing or incerementing of the number
		Fixed	operator++(int);
		Fixed	operator--(int);

///////////////////////////////////////////////////////////////////////////////
//									min and max								 //
///////////////////////////////////////////////////////////////////////////////

		static const Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& min(Fixed& num1, Fixed& num2);

		static const Fixed& max(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);


		int 	getRawBits(void) const;
		void	setRawBits(const int raw);
};


/*An overload of the insertion («) operator that inserts a
	floating-point representation of the fixed-point number
	into the output stream object passed as parameter.*/
	
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif