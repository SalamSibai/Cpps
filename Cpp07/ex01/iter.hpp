/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:48:26 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/02 21:04:33 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>


/**
 * @brief 
 * 
 * @tparam T		type template.
 * @tparam Func 	function template. This allows it to support
					const and nonconst elements depending on how 
					the iter function is called.
 * @param a 		Pointer to first element in the array
 * @param size 		size of array
 * @param func 		function to call
 */
template <typename T, typename Func>
void	iter(T* a, unsigned int size, Func func)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		func(a[i]);
	}
}

#endif