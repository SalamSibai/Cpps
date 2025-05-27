/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:01:39 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/24 20:01:57 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

AForm::AForm() 
	: name("default"), grade_to_sign(1), 
		grade_to_execute(1), is_signed(false) {}

AForm::AForm(std::string n, int gs, int ge) 
	: name(n), grade_to_sign(gs), 
		grade_to_execute(ge), is_signed(false) {}

AForm::AForm(const AForm& other) 
	: name(other.getName()), grade_to_sign(other.getGradeToSign()), 
		grade_to_execute(other.getGradeToExecute()), is_signed(other.getIsSigned()) {}

AForm&	AForm::operator=(const AForm& lhs)
{
	if (this != &lhs)
		is_signed = lhs.getIsSigned();
	return *this;
}

AForm::~AForm()
{
	std::cout << "______________________________________________________\n"
	<< "Destructor called on Aform\n"
	<< "______________________________________________________\n";
}

const std::string AForm::getName() const 
{
	return name;
}

int	AForm::getGradeToSign() const
{
	return grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return grade_to_execute;
}

bool	AForm::getIsSigned() const
{
	return is_signed;
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	is_signed = true;
}

void	AForm::checkRequirments(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExecute() && !is_signed)
		throw	NoRequirmentMet();
	if (executor.getGrade() > getGradeToExecute())
		throw	GradeTooLowException();
	if (!is_signed)
		throw	FormNotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed.");
}

const char* AForm::NoRequirmentMet::what() const throw()
{
	return ("No requirment met - grade too low and form not signed.");
}

std::ostream&	operator<<(std::ostream& os, AForm& inst)
{
	os << inst.getName() <<" Aform:\n" 
		<< "	Grade to sign:		" << inst.getGradeToSign() << "\n"
		<< "	Grade to execute: 	" << inst.getGradeToExecute() << "\n"
		<< "	Signed status:		" << inst.getIsSigned() << std::endl;
	return (os);
}
