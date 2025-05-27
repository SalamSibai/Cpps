/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:33:52 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/23 14:49:33 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Contact.h"

Contact::Contact(void)
{
	return ;
}
Contact::~Contact(void)
{
	return ;
}

Contact& Contact::operator=(const Contact& rhs)
{
	if (this != &rhs)
	{
		first_name = rhs.first_name;
		last_name = rhs.last_name;
		nickname = rhs.nickname;
		phone_number = rhs.phone_number;
		exposed_seceret = rhs.exposed_seceret;
	}
	return (*this);
}

void	Contact::setFirstName(std::string fn)
{
	first_name = fn;
}

void	Contact::setLastName(std::string ln)
{
	last_name = ln;
}

void	Contact::setNickname(std::string nn)
{
	nickname = nn;
}

void	Contact::setPhoneNumber(std::string phone)
{
	phone_number = phone;
}

void	Contact::setSecret(std::string secret)
{
	exposed_seceret = secret;
}

std::string	Contact::getFirstname() const
{
	return first_name;
}

std::string	Contact::getLastname() const
{
	return last_name;
}

std::string	Contact::getNickname() const
{
	return nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string Contact::getSecret() const
{
	return exposed_seceret;
}
