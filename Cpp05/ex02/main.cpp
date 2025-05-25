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

int main()
{
	Bureaucrat a("a", 140);
	std::cout << a << std::endl;
	Bureaucrat b("b", 150);
	std::cout << b << std::endl;
	Bureaucrat c("c", 120);
	std::cout << c << std::endl;

	ShrubberyCreationForm sForm("ShrubberyForm");
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
}
