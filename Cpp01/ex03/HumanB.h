/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:37:36 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:37:37 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.h"

#ifndef HUMANB_H
#define	HUMANB_H

class HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &Weapon);
		void	attack();
		~HumanB();

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif