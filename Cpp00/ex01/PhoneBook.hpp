
#ifndef PhoneBook_H
# define PhoneBook_H


#include <iostream>
#include <string>
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
	void	add_contact();
	void	contact_search();

	/*******************************
				Utilities			
	*******************************/
	bool	add_error_handler(std::string input, std::string input_type, bool alpha);
	bool	search_error_handler(int idx);
	bool	enter_contact_info(Contact *contact);
	bool	enter_first_name(Contact *contact);
	bool	enter_last_name(Contact *contact);
	bool	enter_nickname(Contact *contact);
	bool	enter_secret(Contact *contact);
	bool	enter_number(Contact *contact);
	~PhoneBook(void);
};

#endif