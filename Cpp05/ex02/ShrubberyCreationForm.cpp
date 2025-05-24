/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:52:43 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/24 16:26:41 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default", 1, 1) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string n, int gs, int ge)
	: AForm(n, gs, ge) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) 
{
	//setIsSigned(other.getIsSigned());
	if (getGrade() < 144)
		throw GradeTooHighException();
	is_signed = true;
	//Here, we can decide if it will be signed or not based on the values instead!
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& lhs)
{
	if (this != & lhs)
		is_signed = lhs.getIsSigned();
	return *this;
}