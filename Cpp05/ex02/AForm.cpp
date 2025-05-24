/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:01:39 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/24 16:24:34 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

AForm::AForm() 
	: name("default"), grade_to_sign(1), 
		grade_to_execute(1), is_signed(false) {}

AForm::AForm(std::string n, int gs, int ge) 
	: name(n), grade_to_sign(gs), 
		grade_to_execute(ge), is_signed(false) {}

// AForm::AForm(const AForm& other) 
// 	: name(other.getName()), grade_to_sign(other.getGradeToSign()), 
// 		grade_to_execute(other.getGradeToExecute()), is_signed(other.getIsSigned()) {}

// AForm&	AForm::operator=(const AForm& lhs)
// {
// 	if (this != &lhs)
// 		is_signed = lhs.getIsSigned();
// 	return *this;
// }

AForm::~AForm()
{
	std::cout << "Destructor called on Aform " << name << std::endl;
}

// void AForm::setIsSigned(bool val)
// {
// 	is_signed = val;
// }

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

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}


std::ostream&	operator<<(std::ostream& os, AForm& inst)
{
	os << inst.getName() <<" Aform:\n" 
		<< "	Grade to sign:		" << inst.getGradeToSign() << "\n"
		<< "	Grade to execute: 	" << inst.getGradeToExecute() << "\n"
		<< "	Signed status:		" << inst.getIsSigned() << std::endl;
	return (os);
}
