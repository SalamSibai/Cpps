/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:32:45 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/30 17:32:47 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    (void) av;
    if (ac != 2)
        std::cout << "wrong number o arguments";
    else
        ScalarConverter::convert(av[1]);
    return 0;
}