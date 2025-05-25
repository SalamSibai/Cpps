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
	: AForm("ShrubberyCreation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t)
	: AForm("ShrubberyCreation", 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& lhs)
{
	if (this != & lhs)
		AForm::operator=(lhs);
	return *this;
}

void	ShrubberyCreationForm::drawTree() const
{
	std::fstream file((this->target + "_shrubbery").c_str(), std::fstream::out);
		if (!file)
			throw 1;

		file <<
		"        &&& &&  & &&\n"
		"    && &\\/&\\|& ()|/ @, &&\n"
		"    &\\/(\\/&/&||/& /_/)_&/_&\n"
		" &() &\\/&|()|/&\\/ '%\" & ()\n"
		"&_\\/_&_/&&&|&&%&\\()& /&&\n"
		"&&\\/&|()|/&\\/&|&&&&%\n"
		"()&_---()&\\&\\|&&-&&--%\n"
		"     &&     \\|||\n"
		"             |||\n"
		"             |||\n"
		"             |||\n"
		"       , -=-~  .-^- _\n";

		file.close();
		std::cout << "Shrubbery written to " << target << "_shrubbery\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkRequirments(executor);
	drawTree();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm destructor called.\n";
}