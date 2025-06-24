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
#include <climits>
#include <limits>

class	Validator;

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
};

class BitcoinExchange
{
	private:
		std::map<Date, double>	db;

	protected:
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& lhs);
		~BitcoinExchange();

		void	setContainer(const std::string input, char s);
		void	setDBContainer();

		void	calculate(Date date, double value);
		void	getValue(const std::string input);
		const 	std::pair<Date, double>& findClosestDate();
		void	printResult();
};

class	Validator
{
	Validator();
	Validator(const Validator& other);
	Validator& operator=(const Validator& lhs);
	~Validator();

public:
	static	bool	validateDate(Date d, char s);
	static	bool	validateValue(double v, char s);
	static	void	validateHeader(const std::string line, char s);
	static	void	validateFile(const std::string fname, std::fstream& file);
};

#endif