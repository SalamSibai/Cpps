
#ifndef PhoneBook_H
# define PhoneBook_H

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "Contact.hpp"

/**
 * @brief PhoneBook Class
 * 
 * Properties:
 * 	1) Array of "Contact" objects
 * 
 * Behaviors:
 * 	1) Default constructor
 *  2) add_contact(): Adds a Contact object to the array
 *  3) search_for_contact(): searches for a contact
 * 	4) constructor
 */
class PhoneBook
{
	private:
	Contact	contacts[8];
	int		contact_count;

	public:
	PhoneBook();
	void	addContact(Contact cont);
	void	contactSearch();

	/*******************************
				Utilities			
	*******************************/
	bool	addErrorHandler(std::string input, std::string input_type, bool alpha);
	void	getContacts();
	void	enterContactInfo();
	bool	enterFirstName(Contact *contact);
	bool	enterLastName(Contact *contact);
	bool	enterNickname(Contact *contact);
	bool	enterSecret(Contact *contact);
	bool	enterNumber(Contact *contact);
	void	tableLayout();
	std::string resizeContent(std::string const str, unsigned int len);
	bool	stringType(std::string str, bool alpha);
	~PhoneBook(void);
};

#endif