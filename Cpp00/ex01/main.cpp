
#include "PhoneBook.hpp"

int    check_command(std::string command)
{
	const   char* c_cmd;
	
	c_cmd = command.c_str();
	if (!strcmp("ADD", c_cmd))
		return (1);
	else if (!strcmp("SEARCH", c_cmd))
		return (2);
	else if (!strcmp("EXIT", c_cmd))
		return (3);
	return (0);
}

int main()
{
	std::string	command;
	PhoneBook	phonebook;
	int			cmd_idx;

	std::cout << "Welcome to my phonebook!" << std::endl;
	do
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		std::cout << "What would you like to do today?" << std::endl;
		std::getline(std::cin, command);
		// std::cin >> command;
		cmd_idx = check_command(command);
		if (!cmd_idx)
		{
			std::cout << "Incorrect command! please try again." << std::endl;
			continue;
		}
		 if (command.compare("ADD")) 
			phonebook.add_contact();
		else if (cmd_idx == 2)
			phonebook.contact_search();
		else if (cmd_idx == 3)
		{
			std::cout << "Thank you!" << std::endl;
			break;
		}
	}   while (1);
	return (0);
}
