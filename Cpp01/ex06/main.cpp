/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:25:56 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:26:55 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int ac, char **av)
{
    Harl harl;

	if (ac != 2)
		std::cout << "Wrong number of parameters." << std::endl;
	else
	{
		harl.complain(av[1]);
	}
	return 0;
}