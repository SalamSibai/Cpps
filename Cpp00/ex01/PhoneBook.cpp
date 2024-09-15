
#include "PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 * 
 * Also: contact_count(0) initializes contact_count to 0 [initializer list]
 */
PhoneBook::PhoneBook() : contact_count(0)
{
	return ;
}

bool	PhoneBook::enter_contact_info(Contact *contact)
{
	if (!enter_first_name(contact))
		return (false);
	if (!enter_last_name(contact))
		return (false);
	if (!enter_nickname(contact))
		return (false);
	if (!enter_number(contact))
		return (false);
	if (!enter_secret(contact))
		return (false);
	return (true);
}

/**
 * @brief adds a contact to the phonebook
 * 
 * @param contact 
 * in case anything failed, this makes sure we reset 
 * that contact entry to default
 */
void	PhoneBook::add_contact()
{
	this->contacts[contact_count] = Contact();
	if (!enter_contact_info(&this->contacts[contact_count]))
		this->contacts[contact_count] = Contact();
	else
	{
		contact_count ++;
		if (contact_count == 8)
			contact_count = 0;
		std::cout << "Contact added successfully!" << std::endl;
	}
}

void PhoneBook::contact_search()
{
	int	idx;

	idx = 0;
	std::cout << "Enter index you're searching for:" << std::endl;
	std::cin >> idx;
	if (!search_error_handler(idx))
		std::cout << "Failed to find contact." << std::endl;
	else
		get_contact(idx);
	//else
	//retrieve contact information
}

PhoneBook::~PhoneBook (void)
{
	return ;
}
