/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:51:17 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/20 10:51:57 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>
#include "AForm.hpp"

class AForm;

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

	void	signForm(AForm& f);
	void	executeForm(const AForm& f);
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& inst);
#endif

