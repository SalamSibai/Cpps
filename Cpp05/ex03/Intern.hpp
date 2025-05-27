
#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    AForm* createRobotomyRequestForm(std::string form_target);
    AForm* createShrubberyCreationForm(std::string form_target);
    AForm* createPresidentialPardonForm(std::string form_target);

protected:
    class formDoesntExistException : public std::exception 
	{
		public:
			const char* what() const throw();
		/*throw() after what is dynamic exception specification.
		"this function does not throw any exceptions."*/
	};
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& lhs);
    ~Intern();
    AForm*    makeForm(std::string form_name, std::string form_target);
};

#endif