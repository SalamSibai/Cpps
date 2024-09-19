
#include "PhoneBook.hpp"

bool	alphabetical_string(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(str[i]) && str[i] != ' ')
			return false;
	}
	return (true);
}

bool	numerical_string(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return (true);
}

bool	PhoneBook::add_error_handler(std::string input, std::string input_type, bool alpha)
{
	if (!input.c_str() || input.size() == 0)
	{
		std::cout << "Must enter "<< input_type << "!" << std::endl;
		return (false);
	}
	if (alpha)
	{
 		if (!alphabetical_string(input))
		{
			std::cout << "Wrong entery for "<< input_type << " !" << std::endl;
			return (false);
		}
	}
	else
	{
 		if (!numerical_string(input))
		{
			std::cout << "Wrong entery for "<< input_type << " !" << std::endl;
			return (false);
		}
	}
	return (true);
}
