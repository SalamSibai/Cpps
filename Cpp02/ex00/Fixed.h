/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:51:54 by ssibai            #+#    #+#             */
/*   Updated: 2025/01/07 10:51:55 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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