/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:31:59 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:32:01 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//creates a zombie on the stack
void	randomChump(std::string name)
{
	Zombie random_chump;
	random_chump.setName(name);
	random_chump.announce();
}
