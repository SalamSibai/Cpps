
#include "PhoneBook.hpp"

int main()
{
	std::string	command;
	PhoneBook	phonebook;

	do
	{
		std::cout << "What would you like to do today?" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		else if (command == "ADD") 
			phonebook.enterContactInfo();
		else if (command == "SEARCH")
			phonebook.contactSearch();
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
