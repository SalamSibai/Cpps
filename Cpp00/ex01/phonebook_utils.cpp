
#include "PhoneBook.hpp"

bool	alphabetical_string(std::string str)
{
	const char* c_str;

	c_str = str.c_str();
	while (c_str)
	{
		if(!isalpha(*c_str))
			return (false);
		c_str ++;
	}
	return (true);
}

bool	numerical_string(std::string str)
{
	const char* c_str;

	c_str = str.c_str();
	while (c_str)
	{
		if(!isdigit(*c_str))
			return (false);
		c_str ++;
	}
	return (true);
}

bool	add_error_handler(std::string input, std::string input_type, bool alpha)
{
	if (!input.c_str() || input.size() == 0)
	{
		std::cout << "Must enter "<< input_type << " !" << std::endl;
		return (false);
	}
	if (alpha)
	{
 		if (!alphabetical_string(input))
		std::cout << "Wrong entery for "<< input_type << " !" << std::endl;
			return (false);
	}
	else
	{
 		if (!numerical_string(input))
		std::cout << "Wrong entery for "<< input_type << " !" << std::endl;
			return (false);
	}
	return (true);
}

bool	PhoneBook::search_error_handler(int idx)
{
	if (idx > 7)
	{
		std::cout << "Number entered incorrect!" << std::endl;
		return (false);
	}
	//check if this contact has been filled or not??
	//if (this->contacts[idx])
}