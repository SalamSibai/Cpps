/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:28:58 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/22 09:51:16 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename 	T>
int*	easyfind(T haystack, int needle)
{
	typename T::iterator it = 
	std::find(haystack.begin(), haystack.end(), needle);
	if (it != haystack.end())
		return &(*it);
	return nullptr;	//nullptr is part of CPP11. return NULL instead
}

#endif