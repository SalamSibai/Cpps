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
	try {
			Intern intern;
			AForm *f;
			f = intern.makeForm("blah", "home3");
			f->execute(Bureaucrat());
			delete f;
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}