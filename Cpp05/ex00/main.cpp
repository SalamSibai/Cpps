/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:51:04 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/20 10:51:57 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main()
{
	for (int i = -1; i < 1024; i *= -2)
	{
		std::ostringstream oss;			// creates the stream
		oss << "Instance " << i;		// writes to the stream like cout
		std::string name = oss.str();	// gets the full string result

		try
		{
			Bureaucrat x(name, i);
			std::cout << x << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "i is : " << i << std::endl;
	}

	Bureaucrat best("best", 1);
	try
	{
		best.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat worst("worst", 150);
	try
	{
		worst.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}