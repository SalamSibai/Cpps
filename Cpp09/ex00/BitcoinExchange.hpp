/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:22:54 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/22 16:25:34 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map> 
#include <sstream>
#include <exception>

struct Date
{
	int	year;
	int month;
	int day;

	bool operator<(const Date& other) const 
	{
		if (year != other.year) return year < other.year;
		if (month != other.month) return month < other.month;
		return day < other.day;
	}
}

class BitcoinExchange
{
	private:
		std::map<Date, float>	input;
		std::map<Date, float>	db;

	protected:
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& lhs);
		~BitcoinExchange();

		void	setInputContainer();
		void	setDBContainer();

		void	calculate();
		float	findValue();
		const std::pair<Date, float>& findClosestDate();
		void	printResult();
};

#endif