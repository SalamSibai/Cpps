
#include "PhoneBook.hpp"

int main()
{
	std::string	command;
	PhoneBook	phonebook;

	std::cout << "Welcome to my phonebook!" << std::endl;
	do
	{
		std::cout << "What would you like to do today?" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		else if (command == "ADD") 
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.contact_search();
		else if (command == "EXIT")
		{
			std::cout << "Thank you!" << std::endl;
			break;
		}
		else
			std::cout << "Incorrect command! please try again." << std::endl;
	}	while (1);
	return (0);
}
