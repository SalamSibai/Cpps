/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:51:36 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/20 10:51:38 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout<< "******************* Shrubbery *******************" <<std::endl;

	std::cout<< "\n--------------------- test1 ---------------------\n" <<std::endl; 
	try 
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("shrubbery creation", "shrubbery");
		f->execute(Bureaucrat("ShrubberyBureaucrat", 150));
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<< "\n--------------------- test2 ---------------------\n" <<std::endl; 
	try
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("shrubbery creation", "shrubbery");
		f->execute(Bureaucrat("ShrubberyBureaucrat", 130));
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<< "\n--------------------- test3 ---------------------\n" <<std::endl; 
	try
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("shrubbery creation", "shrubbery");
		Bureaucrat working("ShrubberyBureaucrat", 130);
		working.signForm(*f);
		f->execute(working);
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout<< "\n******************* Presidential *******************" <<std::endl;

	std::cout<< "\n--------------------- test1 ---------------------\n" <<std::endl; 
	try 
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("presidential pardon", "presidential");
		f->execute(Bureaucrat("presidentialBureaucrat", 150));
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<< "\n--------------------- test2 ---------------------\n" <<std::endl; 
	try
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("presidential pardon", "presidential");
		f->execute(Bureaucrat("presidentialBureaucrat", 1));
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<< "\n--------------------- test3 ---------------------\n" <<std::endl; 
	try
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("presidential pardon", "presidential");
		Bureaucrat working("presidentialBureaucrat", 1);
		working.signForm(*f);
		f->execute(working);
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

		std::cout<< "\n******************* Robotomy *******************" <<std::endl;

	std::cout<< "\n--------------------- test1 ---------------------\n" <<std::endl; 
	try 
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("robotomy request", "robotomy");
		f->execute(Bureaucrat("robotomyBureaucrat", 150));
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<< "\n--------------------- test2 ---------------------\n" <<std::endl; 
	try
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("robotomy request", "robotomy");
		f->execute(Bureaucrat("robotomyBureaucrat", 40));
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<< "\n--------------------- test3 ---------------------\n" <<std::endl; 
	try
	{
		Intern intern;
		AForm *f;
		f = intern.makeForm("robotomy request", "robotomy");
		Bureaucrat working("robotomyBureaucrat", 40);
		working.signForm(*f);
		f->execute(working);
		delete f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}