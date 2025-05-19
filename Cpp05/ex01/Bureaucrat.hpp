
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const   std::string name;
	int     grade;

protected:
	class GradeTooHighException : public std::exception 
	{
		public:
			const char* what() const throw();
		/*throw() after what is dynamic exception specification.
		"this function does not throw any exceptions."*/
	};
	class GradeTooLowException	: public std::exception 
	{
		public:
			const char* what() const throw();
		/*throw() after what is dynamic exception specification.
		"this function does not throw any exceptions."*/
	};

public:

	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& lhs);
	~Bureaucrat();

	const	std::string getName() const;
	int		getGrade() const;
	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form& form);
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& inst);
#endif

