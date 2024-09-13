
#include "PhoneBook.hpp"


bool	PhoneBook::enter_first_name(Contact *contact)
{
	std::string	line;

	std::cout<<"Enter first name:"<<std::endl;
	std::getline(std::cin, line);
	if (!add_error_handler(line, "first name", true))
		return (false);
	contact->set_firstname(line);
	return (true);
}

bool	PhoneBook::enter_last_name(Contact *contact)
{
	std::string	line;

	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, line);
	if (!add_error_handler(line, "last name", true))
		return (false);
	contact->set_lastname(line);
	return (true);
}

bool	PhoneBook::enter_nickname(Contact *contact)
{
	std::string	line;

	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, line);
	if (!add_error_handler(line, "nickname", true))
		return (false);
	contact->set_nickname(line);
	return (true);
}

bool	PhoneBook::enter_number(Contact *contact)
{
	std::string	line;

	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, line);
	if (!add_error_handler(line, "phone number", false))
		return (false);
	contact->set_phone_number(line);
	return (true);
}

bool	PhoneBook::enter_secret(Contact *contact)
{
	std::string	line;

	std::cout << "Enter deepest darkest secret:" << std::endl;
	std::getline(std::cin, line);
	if (!add_error_handler(line, "secrect", true))
		return (false);
	contact->set_secret(line);
	std::cout << "Oops, now we get to expose that!" << std::endl;
	return (true);
}
