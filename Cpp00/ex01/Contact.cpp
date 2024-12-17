
#include "Contact.hpp"

/**
 * @brief Construct a new Contact:: Contact object
 */
Contact::Contact(void)
{
	return ;
}

/**
 * SETTERS IMPLEMENTATION
 */
void	Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string number)
{
	this->phone_number = number;
}

void	Contact::setSecret(std::string secret)
{
	this->exposed_seceret = secret;
}

/**
 * GETTERS IMPEMENTATION
 */
std::string	Contact::getFirstname() const
{
	return (this->first_name);
}

std::string	Contact::getLastname() const
{
	return (this->last_name);
}

std::string	Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phone_number);
}

std::string	Contact::getSecret() const
{
	return (this->exposed_seceret);
}
/**
 * @brief Destroy the Contact object
 */

Contact& Contact::operator=(const Contact& rhs)
{
	this->first_name = rhs.getFirstname();
	this->last_name = rhs.getLastname();
	this->nickname = rhs.getNickname();
	this->phone_number = rhs.getPhoneNumber();
	this->exposed_seceret = rhs.getSecret();

	return (*this);
}

Contact::~Contact (void)
{
	return ;
}