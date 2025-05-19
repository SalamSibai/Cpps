
#ifndef FORM_CPP
#define FORM_CPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
	private:
		const	std::string name;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
				bool		is_signed;

	protected:
		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

	public:
		Form();
		Form(std::string n, int gs, int ge);
		Form(const Form& other);
		Form&	operator=(const Form& lhs);
		~Form();

		const	std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat& bx);
};

std::ostream&	operator<<(std::ostream& os, Form& form);

#endif

