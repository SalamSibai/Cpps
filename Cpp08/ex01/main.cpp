/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:49:09 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/14 18:19:12 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main()
{
	int arr[10000];
	for (int i = 0; i < 10000; i++)
		arr[i] = i;
	std::set<int> e(arr, arr + sizeof(arr) / sizeof(int));

	Span s(20000);
	s.addNumber(50);
	s.addNumber(55);
	std::cout << s;

	s.addMany(e);

	std::cout << s;

	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.largestSpan() << std::endl;
	
	return 0;
}