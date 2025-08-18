/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:08:20 by ssibai            #+#    #+#             */
/*   Updated: 2025/07/01 19:53:26 by ssibai           ###   ########.fr       */
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
	try
	{
		setContainer("data.csv", ',');
	}
	catch(const std::exception& e)
	{
		std::cerr << "Database cant be setup\n";
		throw;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db(other.db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& lhs)
{
	if (this != &lhs)
		this->db = lhs.db;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::setContainer(const std::string f, char s)
{
	std::string		line;
	std::fstream	file;

	try
	{
		Validator::validateFile(f, file);
		std::getline(file, line);
		Validator::validateHeader(line, s);
		while (std::getline(file, line))
		{
			std::stringstream linestream(line);
			std::string	date_str, rate_str;

			if (std::count(line.begin(), line.end(), s) != 1)
				throw std::runtime_error("");
			if (std::getline(linestream, date_str, s)
				&& std::getline(linestream, rate_str))
			{
				Date d;
				
				std::stringstream date_stream(date_str);
				std::string year_str, month_str, day_str;

				if (std::getline(date_stream, year_str, '-')
					&& std::getline(date_stream, month_str, '-')
					&& std::getline(date_stream, day_str)
					&& std::count_if(year_str.begin(), year_str.end(), ::isdigit) == static_cast<long>(year_str.size())
					&& std::count_if(month_str.begin(), month_str.end(), ::isdigit) == static_cast<long>(month_str.size())
					&& std::count_if(day_str.begin(), day_str.end(), ::isdigit) == static_cast<long>(day_str.size()))
				{
					std::stringstream(year_str) >> d.year;
					std::stringstream(month_str) >> d.month;
					std::stringstream(day_str) >> d.day;
				}
				else
					throw std::runtime_error("Bad date format.");

				Validator::validateDate(d, s);

				if (!Validator::validateNumberFormat(rate_str))
					throw std::runtime_error("Error: Wrong value format.");

				std::stringstream rate_stream(rate_str);
				double rate;
				rate_stream >> rate;
				Validator::validateValue(rate, s);
				db[d] = rate;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

void	BitcoinExchange::getValue(const std::string input)
{
	std::string		line;
	std::fstream	file;
	try
	{
		Validator::validateFile(input, file);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}

	std::getline(file, line);
	Validator::validateHeader(line, '|');

	while (std::getline(file, line))
	{
		std::stringstream linestream(line);
		std::string	date_str, rate_str, thing;

		if (std::count(line.begin(), line.end(), '|') != 1)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (std::getline(linestream, date_str, ' ')
			&& std::getline(linestream, thing, '|') && thing.empty()
			&& std::getline(linestream, rate_str))
		{

			Date d;

			std::stringstream date_stream(date_str);
			std::string year_str, month_str, day_str;

			if (std::getline(date_stream, year_str, '-') 
				&& std::getline(date_stream, month_str, '-') 
				&& std::getline(date_stream, day_str, ' ') 
				&& std::count_if(year_str.begin(), year_str.end(), ::isdigit) == static_cast<long>(year_str.size())
				&& std::count_if(month_str.begin(), month_str.end(), ::isdigit) == static_cast<long>(month_str.size())
				&& std::count_if(day_str.begin(), day_str.end(), ::isdigit) == static_cast<long>(day_str.size()))	
			{
				std::stringstream(year_str) >> d.year;
				std::stringstream(month_str) >> d.month;
				std::stringstream(day_str) >> d.day;
			}
			else
			{
				std::cerr << "Error: Bad date format => " << date_str << std::endl;
				continue;
			}
			
			if (!Validator::validateDate(d, '|'))
				continue;

			if (!Validator::validateNumberFormat(rate_str))
				continue;
			
			std::stringstream rate_stream(rate_str);
			double rate;
			rate_stream >> rate;
			
			if (!Validator::validateValue(rate, '|'))
				continue;
			calculate(d, rate);
		}
		else
			std::cerr << "Error: Bad input => " <<  line << std::endl;
	}
}

void	BitcoinExchange::calculate(Date& date, double value)
{
	std::cout << date.year << "-";
	if (date.month < 10)
		std::cout << "0" << date.month << "-";
	else
		std::cout << date.month << "-";
	if (date.day < 10)
		std::cout << "0" << date.day << " => ";
	else
		std::cout << date.day << " => ";
	std::cout << value << " = " << std::fixed << std::setprecision(2) << value * findExchangeRate(date) << std::endl;
}

double	BitcoinExchange::findExchangeRate(Date& d)
{
	if (db.count(d) == 1)
		return (db.at(d));

	double value = 0;
	db[d] = 0;
	std::map<Date, double>::iterator it = db.find(d);
	if (it != db.begin())
	{
		value = (--it)->second;
		db.erase(++it);
	}
	return value;
}

///////////////////////		Validator Class		///////////////////////

bool	Validator::validateDate(Date d, char s)
{
	int daysInMonth[] = 
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (d.year < 1000 || d.year > 9999)
	{
		if (s == ',')
			throw std::runtime_error("Error: Wrong date input format");
		return (std::cerr << "Error: Wrong date format." << std::endl, false);
	}
	if (d.month < 1 || d.month > 12)
	{
		if (s == ',')
			throw std::runtime_error("Error: Wrong date input format");
		return (std::cerr << "Error: Wrong date format." << std::endl, false);
	}
	if (d.day < 1 || d.day > daysInMonth[d.month - 1])
	{
		if (s == ',')
			throw std::runtime_error("Error: Wrong date input format");
		return (std::cerr << "Error: Wrong date format." << std::endl, false);
	}
	return true;
}

bool	Validator::validateValue(double v, char s)
{
	if (v < 0)
	{
		if (s == ',')
			throw	std::runtime_error("Error: invalid rate.");
		return (std::cerr << "Error: not a positive number." << std::endl, false);
	}
	if (v > static_cast<double>(std::numeric_limits<int>::max()) ||
		v < static_cast<double>(std::numeric_limits<int>::min()))
	{
		if (s == ',')
			throw	std::runtime_error("Error: invalid rate.");
		return (std::cerr << "Error: too large a number." << std::endl, false);
	}
	if (v > 1000 && s != ',')
		return (std::cerr << "Error: too large a number." << std::endl, false);
	return true;
}

void	Validator::validateHeader(const std::string line, char s)
{
	std::string header = line;
	if (!header.empty() && header[header.size() - 1] == '\r')
		header.erase(header.size() - 1);

	if (s == ',')
	{
		if (header != "date,exchange_rate")
			throw	std::runtime_error("Error: Data Header not found.");
	}
	else
	{
		if (header != "date | value")
			throw	std::runtime_error("Error: Header not found.");
	}
}

void	Validator::validateFile(const std::string fname, std::fstream& file)
{
	file.open(fname.c_str(), std::fstream::in);

	if (file.fail())
		throw std::runtime_error("Error: File does not exist");
}

bool Validator::validateNumberFormat(const std::string& str)
{
	std::string::size_type i = 0;
	int	lspace = 0;

	while (i < str.size() && std::isspace(str[i]))
	{
		++i;
		++lspace;
	}

	if (lspace > 1)
	{
		std::cerr<< "Error: bad value format => " << str << "\n";
		return false;
	}

	if (i < str.size() && (str[i] == '+' || str[i] == '-'))
        ++i;
	bool hasDot = false;
	for (; i < str.size(); ++i)
	{
		char c = str[i];

		if (std::isspace(c))
			break;

		if (!std::isdigit(c))
		{
			if (c == '.' && !hasDot)
				hasDot = true;
			else
			{
				std::cerr<< "Error: bad value format => " << str << "\n";
				return false;
			}
		}
	}

	for (; i < str.size(); ++i)
	{
		if (!std::isspace(str[i]))
		{
			std::cerr<< "Error: bad value format => " << str << "\n";
			return false;
		}
	}
	return true;
}