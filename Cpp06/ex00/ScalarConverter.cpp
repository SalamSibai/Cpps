
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& lhs)
{
    (void)lhs;
    return *this;
}

ScalarConverter::~ScalarConverter()
{ 
	std::cout << "Destructor called\n"; 
}

int		ScalarConverter::checkType(const std::string input)
{
	char* end;
	std::strtold(input.c_str(), &end);

	if (input.length() == 1 && std::isprint(static_cast<unsigned char>(input[0])) 
		&& !std::isdigit(input[0]))
		return CHAR;

	if (end == input.c_str() || *end != '\0') 
		return INVALID;

	return NUMERIC;
}

void	ScalarConverter::fromChar(const		std::string input)
{
	if (std::isprint(input[0]))
		std::cout << "char : '" << static_cast<char>(input[0])<< "'" << std::endl;
	else
		std::cout << "char: Not printable.\n";

	std::cout << "int   : " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float : " << static_cast<float>(input[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

bool	ScalarConverter::isSpecialLiteral(const	std::string input)
{
	std::string lowered;
	for (size_t i = 0; i < input.length(); ++i)
		lowered += std::tolower(static_cast<unsigned char>(input[i]));

	return (lowered == "nan" || lowered == "nanf" ||
			lowered == "inf" || lowered == "+inf" || lowered == "-inf" ||
			lowered == "inff" || lowered == "+inff" || lowered == "-inff");
}

void	ScalarConverter::fromNumeric(const		std::string input)
{
	double	val = std::strtold(input.c_str(), NULL);
	bool	special = isSpecialLiteral(input);

	toChar(val, special);
	toInt(val, special);
	toFloat(val, special);
	toDouble(val, special);
}

/**
 * @brief 	converts to character
 *			takes the value, converts to int, 
 *			then prints out the value of that int to char
 */
void	ScalarConverter::toChar(long double	val, bool isSpecial)
{
	if (val < 0 || val > 127 || isSpecial)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(val)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

void	ScalarConverter::toInt(long double val, bool isSpecial)
{
	if (isSpecial)
		std::cout<< "int: impossible\n";
	else if ((val >= std::numeric_limits<int>::min() 
		&& val <= std::numeric_limits<int>::max()))
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	else
		std::cout<< "int: impossible\n";
}

void	ScalarConverter::toFloat(long double val, bool isSpecial)
{
	std::cout << "float: ";
	float f = static_cast<float>(val);
	if (isSpecial)
		std::cout << f << "f" << std::endl;
	else if (val >= -std::numeric_limits<float>::max() 
		&& val <= std::numeric_limits<float>::max())
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << f << "f" << std::endl;
	}
	else
		std::cout << "impossible\n"; 
}

void	ScalarConverter::toDouble(long double val, bool isSpecial)
{
	std::cout << "double: ";
	double d = static_cast<double>(val);
	if (isSpecial)
		std::cout << d << std::endl;
	else if (val >= -std::numeric_limits<double>::max()
		&& val <= std::numeric_limits<double>::max())
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << d << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}


void	ScalarConverter::convert(const std::string input)
{
	(void) input;
	int	type = checkType(input);
	switch (type)
	{
		case	CHAR:
			fromChar(input);
			break;
		case	NUMERIC:
			fromNumeric(input);
			break;
		case	INVALID:
			std::cout << "char  : impossible" << std::endl; 
			std::cout << "int   : impossible" << std::endl; 
			std::cout << "float : impossible" << std::endl; 
			std::cout << "double: impossible" << std::endl;
			break;
	}
}



