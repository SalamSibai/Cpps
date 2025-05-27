/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:29:52 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:29:56 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.h"

void	Harl::complain(std::string level)
{
	std::string  str_arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*funptr[4])();
	funptr[0]= &Harl::debug;
	funptr[1]= &Harl::info;
	funptr[2]= &Harl::warning;
	funptr[3]= &Harl::error;

	int	i = 0;
	while (i < 4 && str_arr[i].compare(level.c_str()) != 0)
		i++;
	
	switch(i)
	{
		case 0:
			(this->*funptr[0])();
		case 1:
			(this->*funptr[1])();
		case 2:
			(this->*funptr[2])();
		case 3:
			(this->*funptr[3])();
			break;
		default:
			std::cout << "[doesn't matter really..]" << std::endl; 
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I AM DEBUGGING!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I AM GIVING INFO!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I AM GIVING WARGNING!\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "I AM ERROR!\n" << std::endl;
}