
#include "PhoneBook.hpp"

void	table_layout()
{
	for (int i = 0; i < 45; i ++)
	{
		if (i == 0)
			std::cout << "╔";
		else if (i == 44)
			std::cout << "╗";
		else
			std::cout << "═";
	}
	std::cout << std::endl;
	std::cout << "║index     |first name|last name |nickname  ║"  << std::endl;
	for (int i = 0; i < 45; i ++)
	{
		if (i == 0)
			std::cout << "╚";
		else if (i == 44)
			std::cout << "╝";
		else
			std::cout << "═";
	}
	std::cout << std::endl;
}


void	PhoneBook::get_contacts()
{
	int	idx;

	idx = 0;
	table_layout();
	while (idx < contact_count)
	{
		std::cout << "First name: " << PhoneBook::contacts[idx].get_firstname() << std::endl;
		std::cout << "Last name: " <<  PhoneBook::contacts[idx].get_lastname() << std::endl;
		std::cout << "Nickname: " <<  PhoneBook::contacts[idx].get_nickname() << std::endl;
		std::cout << "Phone number: " <<  PhoneBook::contacts[idx].get_phone_number() << std::endl;
		std::cout << "secret: " <<  PhoneBook::contacts[idx].get_secret() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		idx ++;
	}
}
