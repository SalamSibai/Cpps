/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:26:11 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/24 20:29:13 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
		std::cerr << "Error: wrong number of arguments";
	
	std::string input;
	for (int i = 1; i < ac; ++i)
	{
		input += av[i];
		if (i < ac - 1)
			input += " ";
	}

	RPN rpn;
	try
	{
		rpn.getResult(input);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
	
}