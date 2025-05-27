/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:32:12 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:32:15 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie random_zombie("random");
	Zombie *actual_zombie = NULL;

	actual_zombie = newZombie("real");
	actual_zombie->announce();
	random_zombie.announce();
	delete (actual_zombie);
}
