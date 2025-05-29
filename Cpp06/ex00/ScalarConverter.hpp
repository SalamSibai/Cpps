

#ifndef	SCALARCONVERTER.HPP
#define	SCALARCONVERTER_HPP

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& lhs);
	~ScalarConverter();

	enum dType { CHAR, INT, FLOAT, DOUBLE };
	static	int		checkType(const		std::string input);

	static	void	fromChar(const		std::string input);
	static	void	fromInt(const		std::string input);
	static	void	fromFloat(const		std::string input);
	static	void	fromDouble(const	std::string input);

	static	void	toChar();
	static	void	toInt();
	static	void	toFloat();
	static	void	toDouble();

public:
	static void	convert(const std::string literal);
};

#endif