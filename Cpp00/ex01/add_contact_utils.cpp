
#include "PhoneBook.hpp"

bool	PhoneBook::enterFirstName(Contact *cont)
{
	std::string	line;

	std::cout<<"Enter first name:"<<std::endl;
	std::cin >> line;
	if (!addErrorHandler(line, "first name", true))
		return (false);
	cont->setFirstName(line);
	return (true);
}

bool	PhoneBook::enterLastName(Contact *cont)
{
	std::string	line;

	std::cout << "Enter last name:" << std::endl;
	std::cin >> line;
	if (!addErrorHandler(line, "last name", true))
		return (false);
	cont->setLastName(line);
	return (true);
}

bool	PhoneBook::enterNickname(Contact *cont)
{
	std::string	line;

	std::cout << "Enter nickname:" << std::endl;
	std::cin >> line;
	if (!addErrorHandler(line, "nickname", true))
		return (false);
	cont->setNickname(line);
	return (true);
}

bool	PhoneBook::enterNumber(Contact *cont)
{
	std::string	line;

	std::cout << "Enter phone number:" << std::endl;
	std::cin >> line;
	if (!addErrorHandler(line, "phone number", false))
		return (false);
	cont->setPhoneNumber(line);
	return (true);
}

bool	PhoneBook::enterSecret(Contact *cont)
{
	std::string	line;

	std::cout << "Enter deepest darkest secret:" << std::endl;
	std::cin >> line;
	if (!addErrorHandler(line, "secrect", true))
		return (false);
	cont->setSecret(line);
	std::cout << "Oops, now we get to expose that!" << std::endl;
	return (true);
}
