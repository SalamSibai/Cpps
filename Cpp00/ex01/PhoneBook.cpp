
#include "PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 * 
 * Also: contact_count(0) initializes contact_count to 0 [initializer list]
 */
PhoneBook::PhoneBook() : contact_count(0)
{
	std::cout << "Welcome to my phonebook!" << std::endl;
}

void	PhoneBook::enterContactInfo()
{
	Contact temp;

	if (!enterFirstName(&temp))
		return ;
	if (!enterLastName(&temp))
		return ;
	if (!enterNickname(&temp))
		return ;
	if (!enterNumber(&temp))
		return ;
	if (!enterSecret(&temp))
		return ;

	addContact(temp);
}

/**
 * @brief adds a contact to the phonebook
 * 
 * @param contact 
 * in case anything failed, this makes sure we reset 
 * that contact entry to default
 */
void	PhoneBook::addContact(Contact cont)
{
	this->contacts[contact_count] = cont;
	this->contact_count ++;
	if (this->contact_count == 8)
		this->contact_count = 0;
}

/**
 * @brief shows list of all saved elements
 * 
 */
void PhoneBook::contactSearch()
{
	if (contact_count == 0)
		std::cout << "NO CONTACTS HAVE BEEN SAVED!" << std::endl;
	else
		getContacts();
}

PhoneBook::~PhoneBook (void)
{
	return ;
}
