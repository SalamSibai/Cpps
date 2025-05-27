/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:24:59 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/23 12:33:41 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string nickname;
	std::string	phone_number;
	std::string	exposed_seceret;

	public:
	Contact(void);
	//setters
	void	setFirstName(std::string fn);
	void	setLastName(std::string ln);
	void	setNickname(std::string nn);
	void	setPhoneNumber(std::string pn);
	void	setSecret(std::string secret);

	//Getters
	std::string	getFirstname() const;
	std::string	getLastname() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getSecret() const;

	//operator overloading:
	Contact& operator=(const Contact& rhs);
	~Contact(void);
};