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

std::string trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";

	std::size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

int main(int ac, char** av)
{
	if (ac < 2)
	std::cerr << "Error: wrong number of arguments";
	
	std::string input;
	for (int i = 1; i < ac; ++i)
	{
		std::string token = trim(av[i]);
		if (!token.empty())
		{
			input += token;
			if (i < ac - 1)
			input += " ";
		}
	}

	RPN rpn;
	try
	{
		rpn.getResult(input);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
	return 0;
	
}