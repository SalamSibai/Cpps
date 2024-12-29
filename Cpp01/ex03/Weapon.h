/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:08:13 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:10:01 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_H
#define	WEAPON_H

class Weapon
{
	public:
		Weapon(){};
		Weapon(std::string type);
		const std::string&	getType() const;
		void		setType(std::string type);
		~Weapon();

	private:
		std::string type;
};

#endif