
#include "Contact.hpp"

/**
 * @brief Construct a new Contact:: Contact object
 */
Contact::Contact()
{
	return ;
}

/**
 * SETTERS IMPLEMENTATION
 */
void	Contact::set_firstname(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_phone_number(std::string number)
{
	this->phone_number = number;
}

void	Contact::set_secret(std::string secret)
{
	this->exposed_seceret = secret;
}

/**
 * GETTERS IMPEMENTATION
 */
std::string	Contact::get_firstname()
{
	return (this->first_name);
}

std::string	Contact::get_lastname()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	Contact::get_secret()
{
	return (this->exposed_seceret);
}
/**
 * @brief Destroy the Contact object
 */
Contact::~Contact (void)
{
	return ;
}