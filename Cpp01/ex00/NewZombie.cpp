/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:41:41 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:42:05 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief This creates a zombie object on the heap
 * 
 * @param name the name of the zombie
 * @return Zombie* returns a new instance of the zombie
 */
Zombie* newZombie(std::string name)
{
	Zombie* new_zombie = new Zombie(name);
	return (new_zombie);
}
