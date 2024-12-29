/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:33:19 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:33:21 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

void	Zombie::setName(std::string n)
{
	this->_name = n;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dying." << std::endl;
}
