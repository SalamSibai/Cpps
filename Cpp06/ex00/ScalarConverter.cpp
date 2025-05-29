
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
	long double		val;
	char			*end;

	val = std::strtold(input.c_str(), &end);
	if (input.length() == 1 && std::isprint(input[0]) && static_cast<std::string>(end).size() == 1)
		return CHAR;
	// else if (input.c_str() == end)
	// 	return INVALID;
	// else if (std::isinf(val) || std::isnan(val))
	// 	return SPECIAL;
	else if ((val >= std::numeric_limits<int>::min() 
				&& val <= std::numeric_limits<int>::max()) 
				&& (input.find('.') == std::string::npos)) // npos equevallent of "not found"
		return INT;
	else if ((val >= -std::numeric_limits<float>::max() 
				&& val <= std::numeric_limits<float>::max())
				&& (input.find('.') != std::string::npos)
				&& (static_cast<std::string>(end).size() == 1 && end[0] == 'f'))
		return FLOAT;
	else if ((val >= -std::numeric_limits<double>::max()
				&& val <= std::numeric_limits<double>::max())
				&& (input.find('.') != std::string::npos) && end[0] == '\0')
		return DOUBLE;
	// return  NOTAPPLICABLE;
}

void	ScalarConverter::fromChar(const		std::string input)
{
	
}

void	ScalarConverter::fromInt(const		std::string input)
{

}

void	ScalarConverter::fromFloat(const		std::string input)
{

}

void	ScalarConverter::fromDouble(const		std::string input)
{

}

void	ScalarConverter::convert(const std::string input)
{
	int	type = checkType(input);
	switch (type)
	{
		case	CHAR:
			fromChar(input);
			break;
		case	INT:
			break;
		case	FLOAT:
			break;
		case	DOUBLE:
			break;
	}
}



