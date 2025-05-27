/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:53:01 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/23 14:50:50 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.h"

int main()
{
	std::string	command;
	PhoneBook	phonebook;

	do
	{
		std::cout << "What would you like to do today?" << std::endl;
		if (! std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break ;
		}
		else if (command == "ADD")
			phonebook.enterInfo();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
		{
			std::cout << "Thank you!" << std::endl;
			break;
		}
		else
			std::cout << "Incorrect command! please try again." << std::endl;
	}	while (1);
	return (0);
}
