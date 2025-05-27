/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:00:07 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 15:08:17 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	contact_count = 0;
	index = 0;
}
PhoneBook::~PhoneBook()
{
	return ;
}

///////////////////////////////////////////////////////////////////////////////
//  								ADD CONTACT								 //
///////////////////////////////////////////////////////////////////////////////

void	PhoneBook::enterInfo()
{
	if (!enterFirstName())
		return ;
	if (!enterLastName())
		return ;
	if (!enterNickname())
		return ;
	if (!enterPhoneNum())
		return ;
	if (!enterSecret())
		return ;
	add();
}

bool	PhoneBook::enterFirstName()
{
	std::string	line;

	std::cout<<"Enter first name:"<<std::endl;
	if (!std::getline(std::cin, line))
		exit(1) ;
	if (!addErrorHandler(line, "first name", true))
		return (false);
	contact.setFirstName(line);
	return (true);
}

bool	PhoneBook::enterLastName()
{
	std::string	line;

	std::cout << "Enter last name:" << std::endl;
	if (!std::getline(std::cin, line))
		exit(1) ;
	if (!addErrorHandler(line, "last name", true))
			return (false);
	contact.setLastName(line);
	return (true);
}

bool	PhoneBook::enterNickname()
{
	std::string	line;

	std::cout << "Enter nickname:" << std::endl;
	if (! std::getline(std::cin, line))
		exit (1);
	if (!addErrorHandler(line, "nickname", true))
		return (false);
	contact.setNickname(line);
	return (true);
}
bool	PhoneBook::enterPhoneNum()
{
	std::string	line;

	std::cout << "Enter phone number:" << std::endl;
	if (! std::getline(std::cin, line))
		exit (1);
	if (!addErrorHandler(line, "phone number", false))
		return (false);
	contact.setPhoneNumber(line);
	return (true);
}

bool	PhoneBook::enterSecret()
{
	std::string	line;

	std::cout << "Enter deepest darkest secret:" << std::endl;
	if (! std::getline(std::cin, line))
		exit (1);
	if (!addErrorHandler(line, "secrect", true))
		return (false);
	contact.setSecret(line);
	std::cout << "Oops, now we get to expose that!" << std::endl;
	return (true);
}
bool	PhoneBook::addErrorHandler(std::string input,
			std::string input_type, bool alpha)
{
	if (!input.c_str() || input.size() == 0)
	{
		std::cout << "Must enter "<< input_type << "!" << std::endl;
		return (false);
	}
	if (!stringType(input, alpha))
	{
		std::cout << "Wrong entery for "<< input_type << " !" << std::endl;
		return (false);
	}
	return (true);
}

void	PhoneBook::add()
{
	contacts[contact_count % 8] = contact;
	if (index != 8)
		index ++;
	contact_count++;
}

///////////////////////////////////////////////////////////////////////////////
//  							SEARCH CONTACT								 //
///////////////////////////////////////////////////////////////////////////////
void	PhoneBook::search() const
{
	if (contact_count == 0)
		std::cout << "NO CONTACTS HAVE BEEN SAVED!" << std::endl;
	else
		getContact();
}

void	PhoneBook::getContact() const
{
	int	idx;
	std::string line;
	std::stringstream ss;

	idx = 0;
	tableLayout();
	while (idx < index)
	{
		std::cout << "║         " << idx + 1 <<"|" << resizeContent(contacts[idx].getFirstname(), 9, false) << "|" 
			<< resizeContent(contacts[idx].getLastname(), 9, false) << "|" << resizeContent(contacts[idx].getNickname(), 9, false) << "║" <<std::endl;
		std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
		idx ++;
	}

	idx = 0;
	std::cout << "Enter the index of the contact you wish to retrieve: ";
	if (!std::getline(std::cin, line))
		exit(1);
	ss << line;
	ss >> idx;
	idx --;

	if (idx < index && idx >= 0)
	{
		std::cout << "╔═════════════════════════════════════════════════════════════════╗" << std::endl;
		std::cout << "║First name   ║" << resizeContent(contacts[idx].getFirstname(), 50, true) << "║" << std::endl;
		std::cout << "║Last name    ║" << resizeContent(contacts[idx].getLastname(), 50, true) << "║" << std::endl;
		std::cout << "║Nickname     ║" << resizeContent(contacts[idx].getNickname(), 50, true) << "║" << std::endl;
		std::cout << "║Phone number ║" << resizeContent(contacts[idx].getPhoneNumber(), 50, true) << "║" << std::endl;
		std::cout << "║secret       ║" << resizeContent(contacts[idx].getSecret(), 50, true) << "║" << std::endl;
		std::cout << "╚═════════════════════════════════════════════════════════════════╝" << std::endl;
	}
	else
		std::cout << "Wrong index entry!" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
//  						NON MEMBER FUNCTIONS							 //
///////////////////////////////////////////////////////////////////////////////

bool	stringType(std::string str, bool alpha)
{
	if (alpha)
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isalpha(str[i]) && str[i] != ' ')
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i]))
				return false;
		}
	}
	return (true);
}

std::string	resizeContent(std::string const str, unsigned int len, bool detailed)
{
	std::string temp;

	temp = str;
	if (temp.size() > len)
		temp.resize(len), temp += '.';
	if (!detailed)
	{
		while (temp.size() < (len + 1))
		{
			temp = " " + temp;
		}
	}
	else
	{
		if (temp.size() < (len + 1))
			temp.append((len+1) - temp.size(), ' ');
	}
	return (temp);
}

void	tableLayout()
{
	std::cout << "╔═══════════════════════════════════════════╗" << std::endl;
	std::cout << "║     index|First Name| last name|  nickname║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
}
