/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:06:31 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/10 17:54:28 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

int main()
{
    Array<std::string>  strs(2);
    Array<int>          nums(5);
    
    strs[0] = "hello";
    strs[1] = "world";

    for (int i = 1; i < 6; i++)
    {
        nums[i-1] = i;
    }

    std::cout << strs[0] << " " << strs[1] << "\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << nums[i] << " ";
    }

    std::cout << "\nnums size: " << nums.size() << std::endl;
    std::cout << "strs size: " << strs.size() << std::endl;

    return 0;
}