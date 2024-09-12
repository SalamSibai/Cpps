
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
 * @brief Destroy the Contact object
 */
Contact::~Contact (void)
{
	return ;
}