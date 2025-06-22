/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:08:20 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/22 16:22:10 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/**
 * @brief 
 *	read input line:
 *		for validating the input: Read from file:
 *		1) 	convert all to ints, make sure first int is 4 digits, second is
 *			less than 12, 3rd is less than 31
 *		1) 	Create 2 pairs:
 *			- 	one is the pair from the input, with one being date, 
 *				and the other value
 *			-	the other is the DB stored, the same way.
 *
 *		2) 	Compare the two:
 *			-	for dates:
 *
 */

 #include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	setDBContainer();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& const)
{
	this->input = other.input;
	this->db = other.db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& lhs)
{
	if (this != &other)
	{
		this->input = other.input;
		this->db = other.db;
	}
	return this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::setInputContainer()
{
	std::fstream file(std::string(fileName).c_str(), std::fstream::in);
	std::stringstream stream;
	std::string buff;

	if (file.fail())
		throw std::runtime_error("File does not exist");
	
	stream << file.rdbuf();
	while (std::getline(stream, buff, '\n'))
	{
		
	}
}


