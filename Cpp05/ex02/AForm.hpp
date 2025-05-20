/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:01:45 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/20 11:04:59 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FORM_CPP
#define FORM_CPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm
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
		AForm();
		AForm(std::string n, int gs, int ge);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& lhs);
		~AForm();

		const	std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat& bx);
};

std::ostream&	operator<<(std::ostream& os, AForm& form);

#endif

