/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:35:18 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/02 20:47:03 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
#define	WHATEVER_HPP

#include <iostream>

template <typename t>
void	swap(t& one, t& two)
{
	t temp;

	temp = two;
	two = one;
	one = temp;
}

template <typename t>
t	min(t f, t s)
{
	if (f > s)
		return s;
	return f;
}

template <typename t>
t	max(t f, t s)
{
	if (f > s)
		return f;
	return s;
}

#endif
