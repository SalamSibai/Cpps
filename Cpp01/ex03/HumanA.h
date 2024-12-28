/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:37:23 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:37:29 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.h"


#ifndef HUMANA_H
#define	HUMANA_H

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();
		~HumanA();

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif