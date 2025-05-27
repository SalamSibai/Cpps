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
#include "Form.hpp"

int main()
{
	Bureaucrat jack("jack", 140);
	std::cout << jack << std::endl;
	Bureaucrat bill("bill", 4);
	// try {
	// 	Bureaucrat curtis("curtis", 0);
	// 	std::cout << curtis << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << e.what() << "\n";
	// }
	std::cout << bill << std::endl;


	Form tax = Form("Tax", 1, 2);
	try 
	{
		tax.beSigned(bill);
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << tax;
	// bill.signForm(tax);

	
	// try {
	// 	tax.beSigned(jack);
	// } catch (std::exception& e) {
	// 	std::cerr << e.what() << "\n";
	// }
	// std::cout << tax;
	// jack.signForm(tax);
	
	return (0);
}
