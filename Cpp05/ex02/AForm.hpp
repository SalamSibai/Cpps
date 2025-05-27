/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:01:45 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/24 20:08:40 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef AFORM_CPP
#define AFORM_CPP

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
		class FormNotSignedException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

	public:
		AForm();
		AForm(std::string n, int gs, int ge);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& lhs);
		virtual ~AForm();

		const	std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat& bx);

		void				checkRequirments(Bureaucrat const & executor) const;
		virtual void 		execute(Bureaucrat const & executor) const = 0;
	};

std::ostream&	operator<<(std::ostream& os, AForm& form);

#endif

