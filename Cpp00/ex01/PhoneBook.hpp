
#ifndef PhoneBook_H
# define PhoneBook_H


#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact	contacts[8];

	public:
	PhoneBook();
	void	ft_add();
	Contact	ft_search(int idx);
	void	ft_exit();
	~PhoneBook();
};

#endif