/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:02:43 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:02:49 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *z = NULL;

	z = zombieHorde(5, "zombies");

	for (int i = 0; i < 5; i++)
	{
		z[i].announce();
	}
	delete[] z;

	return (0);
}
