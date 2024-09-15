
#include "PhoneBook.hpp"

void	PhoneBook::get_contact(int idx)
{
	std::cout<< "First name: " << PhoneBook::contacts[idx].get_firstname() << std::endl;
}
