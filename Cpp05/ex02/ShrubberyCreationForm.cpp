/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:52:43 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/24 20:02:27 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default", 1, 1) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string n, int gs, int ge)
	: AForm(n, gs, ge) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& lhs)
{
	if (this != & lhs)
		AForm::operator=(lhs);
	return *this;
}