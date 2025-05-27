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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat a("a", 140);
	std::cout << a << std::endl;
	Bureaucrat b("b", 138);
	std::cout << b << std::endl;
	Bureaucrat c("c", 120);
	std::cout << c << std::endl;
	
	std::cout<< "---------- Shrubbery ----------\n" <<std::endl; 
	ShrubberyCreationForm sForm("tree");
	try
	{
		sForm.execute(a);
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	try
	{
		b.signForm(sForm);
		sForm.execute(b);
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	try
	{
		c.signForm(sForm);
		sForm.execute(c);
	}
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}

	std::cout<< "---------- Robotomy ----------\n" <<std::endl; 

	RobotomyRequestForm rForm("RobotomyRequest");


	Bureaucrat a_r("a_r", 140);
	std::cout << a_r << std::endl;
	Bureaucrat b_r("b_r", 40);
	std::cout << b_r << std::endl;
	Bureaucrat c_r("c_r", 40);
	std::cout << c_r << std::endl;

	try
	{
		rForm.execute(a_r);
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	try
	{
		rForm.execute(b_r);
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	try
	{
		c_r.signForm(rForm);
		rForm.execute(c_r);
	}
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}

	std::cout<< "---------- Presidential ----------\n" <<std::endl; 
	PresidentialPardonForm pForm("PresidentialForm");

	Bureaucrat a_p("a_p", 140);
	std::cout << a_p << std::endl;
	Bureaucrat b_p("b_p", 5);
	std::cout << b_p << std::endl;
	Bureaucrat c_p("c_p", 5);
	std::cout << c_p << std::endl;

	try
	{
		pForm.execute(a_p);
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	try
	{
		pForm.execute(b_p);
	} 
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	try
	{
		c_p.signForm(pForm);
		pForm.execute(c_p);
	}
	catch (std::exception& e) 
	{
		std::cerr << "Couldn't execute because " << e.what() << "\n";
	}
	
}
