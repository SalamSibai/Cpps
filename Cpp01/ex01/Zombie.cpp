/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:02:33 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:02:36 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

void	Zombie::setName(const std::string& n)
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
