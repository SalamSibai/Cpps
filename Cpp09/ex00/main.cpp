/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:26:36 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/22 10:39:32 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr <<"Error: Input file expected.\n";
		return 1;
	}
	
	try
	{
		BitcoinExchange bt;
		bt.getValue(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed\n";
		return 1;
	}
	return 0;
}