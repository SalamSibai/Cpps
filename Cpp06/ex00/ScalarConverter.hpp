

#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& lhs);
	~ScalarConverter();

	enum dType { CHAR, NUMERIC, INVALID };
	static	int		checkType(const		std::string input);

	static	void	fromChar(const		std::string input);
	static	void	fromNumeric(const	std::string input);
	static	bool	isSpecialLiteral(const	std::string input);

	static	void	toChar(long double val, bool isSpecial);
	static	void	toInt(long double	val, bool isSpecial);
	static	void	toFloat(long double	val, bool isSpecial);
	static	void	toDouble(long double	val, bool isSpecial);


public:
	static void	convert(const std::string literal);
};

#endif