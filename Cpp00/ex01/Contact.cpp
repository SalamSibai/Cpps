
#include "Contact.hpp"

/**
 * @brief Construct a new Contact:: Contact object
 */
Contact::Contact()
{
	set_index(0);
	set_firstname("fn");
	set_lastname("ln");
	set_nickname("nn");
}

/**
 * SETTERS IMPLEMENTATION
 */
void	Contact::set_index(int idx)
{
	this->index = idx;
}

void	Contact::set_firstname(std::string fn)
{
	this->first_name = fn;
}

void	Contact::set_lastname(std::string ln)
{
	this->last_name = ln;
}

void	Contact::set_nickname(std::string nn)
{
	this->nickname = nn;
}

void	Contact::set_secret(std::string secret)
{
	this->exposed_seceret = secret;
}

/**
 * GETTERS IMPEMENTATION
 */

int	Contact::get_index()
{
	return (this->index);
}

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