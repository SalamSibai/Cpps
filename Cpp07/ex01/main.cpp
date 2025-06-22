/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:03:14 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/02 21:03:16 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.hpp"
#include <iostream>

void addOne(int& x)
{
	++x;
}

int main(void)
{
	int arr[] = {1, 2, 3};
	int len  = 3;
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\n";
	iter(arr, len, addOne);
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\n";
	return 0;
}