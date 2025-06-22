/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:28:55 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/14 13:00:26 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < 6; i ++)
    {
        int* result = easyfind(v, i);
        if (result)
            std::cout << *result << std::endl;
        else
            std::cout << "null" << std::endl;
    }
    
    return 0;
}