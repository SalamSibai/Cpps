
#include "PhoneBook.hpp"

bool	PhoneBook::stringType(std::string str, bool alpha)
{
	if (alpha)
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isalpha(str[i]) && str[i] != ' ')
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i]))
				return false;
		}
	}
	return (true);
}

bool	PhoneBook::addErrorHandler(std::string input, std::string input_type, bool alpha)
{
	if (!input.c_str() || input.size() == 0)
	{
		std::cout << "Must enter "<< input_type << "!" << std::endl;
		return (false);
	}
	if (!stringType(input, alpha))
	{
		std::cout << "Wrong entery for "<< input_type << " !" << std::endl;
		return (false);
	}
	return (true);
}
