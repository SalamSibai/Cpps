/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:00:56 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/30 19:44:30 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

std::string trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";

	std::size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

int main(int ac, char **av) 
{
	if (ac < 2) 
	{
		std::cerr << "Error: wrong number of arguments\n";
		return 1;
	}


	try 
	{
		std::string input;
		for (int i = 1; i < ac; ++i) 
		{
			input += av[i];
			if (i < ac - 1)
				input += " ";
		}
	
		PmergeMe<std::deque<int> > deque_sorter;
		PmergeMe<std::vector<int> > vector_sorter;
		
		vector_sorter.sort(input);
		std::cout << "Before: " << input << "\n";
		std::cout << "After (with std::vector): ";
		vector_sorter.printContainer();
		
		deque_sorter.sort(input);
		std::cout << "After (with std::deque):  ";
		deque_sorter.printContainer();
		
		std::cout << "Time to process a range of " << vector_sorter.getSize() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(6) << vector_sorter.getExecutionTime() << " us\n";
		std::cout << "Time to process a range of " << deque_sorter.getSize() << " elements with std::deque  : ";
		std::cout << std::fixed << std::setprecision(6) << deque_sorter.getExecutionTime() << " us\n";
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Failed.\n";
		return 1;
	}

	return 0;
}