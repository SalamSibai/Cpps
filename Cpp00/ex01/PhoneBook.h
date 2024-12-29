/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:23:22 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 15:08:16 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include "Contact.h"

class PhoneBook
{
	private:
		Contact	contacts[8];
		Contact	contact;
		int		contact_count;
		int		index;

	public:
		PhoneBook();
		~PhoneBook();
		void	enterInfo();
		bool	enterFirstName();
		bool	enterLastName();
		bool	enterNickname();
		bool	enterPhoneNum();
		bool	enterSecret();
		bool	addErrorHandler(std::string input, std::string input_type, bool alpha);
		void	add();
		void	search() const;
		void	getContact() const;
};

//Non member function: not directly related to phonebook
bool		stringType(std::string str, bool alpha);
void		tableLayout();
std::string	resizeContent(std::string const str, unsigned int len, bool detailed);

