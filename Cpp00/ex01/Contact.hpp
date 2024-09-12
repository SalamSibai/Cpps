
#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	private:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string nickname;
	std::string	exposed_seceret;

	public:
	Contact();

	//setters
	void	set_index(int idx);
	void	set_firstname(std::string fn);
	void	set_lastname(std::string ln);
	void	set_nickname(std::string nn);
	void	set_secret(std::string secret);

	//Getters
	int			get_index();
	std::string	get_firstname();
	std::string	get_lastname();
	std::string	get_nickname();
	std::string	get_secret();
	~Contact(void);

};

#endif