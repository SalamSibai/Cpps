
#ifndef CONTACT_H
# define CONTACT_H

#include <string>

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
	void	set_firstname(std::string fn);
	void	set_lastname(std::string ln);
	void	set_nickname(std::string nn);
	void	set_phone_number(std::string pn);
	void	set_secret(std::string secret);

	//Getters
	std::string	get_firstname();
	std::string	get_lastname();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_secret();
	~Contact(void);

};

#endif