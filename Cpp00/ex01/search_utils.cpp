
#include "PhoneBook.hpp"

std::string	PhoneBook::resizeContent(std::string const str, unsigned int len)
{
	std::string temp;

	temp = str;
	if (temp.size() > len)
		temp.resize(len), temp += '.';
	if (temp.size() < (len + 1))
		temp.append((len+1) - temp.size(), ' ');
	return (temp);
}


void	PhoneBook::tableLayout()
{
	std::cout << "╔═══════════════════════════════════════════╗" << std::endl;
	std::cout << "║index     |First Name|last name |nickname  ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
}


void	PhoneBook::getContacts()
{
	int	idx;

	idx = 0;
	tableLayout();
	while (idx < contact_count)
	{
		std::cout << "║     " << idx + 1 << "    |" << resizeContent(contacts[idx].getFirstname(), 9) << "|" 
			<< resizeContent(contacts[idx].getLastname(), 9) << "|" << resizeContent(contacts[idx].getNickname(), 9) << "║" <<std::endl;
		std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
		idx ++;
	}

	idx = 0;
	std::cout << "Enter the index of the contact you wish to retrieve: ";
	std::cin >> idx;
	idx --;

	if (idx < contact_count && idx >= 0)
	{
		std::cout << "╔═════════════════════════════════════════════════════════════════╗" << std::endl;
		std::cout << "║First name   ║" << resizeContent(contacts[idx].getFirstname(), 50) << "║" << std::endl;
		std::cout << "║Last name    ║" << resizeContent(contacts[idx].getLastname(), 50) << "║" << std::endl;
		std::cout << "║Nickname     ║" << resizeContent(contacts[idx].getNickname(), 50) << "║" << std::endl;
		std::cout << "║Phone number ║" << resizeContent(contacts[idx].getPhoneNumber(), 50) << "║" << std::endl;
		std::cout << "║secret       ║" << resizeContent(contacts[idx].getSecret(), 50) << "║" << std::endl;
		std::cout << "╚═════════════════════════════════════════════════════════════════╝" << std::endl;
	}
	else
		std::cout << "Wrong index entry!" << std::endl;
}
