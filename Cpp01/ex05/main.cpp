/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:38:14 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:38:17 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");
	return 0;
}
