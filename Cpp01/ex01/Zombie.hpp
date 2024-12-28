/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:02:38 by ssibai            #+#    #+#             */
/*   Updated: 2024/12/28 19:02:40 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name)
	{
		setName(name);
	}
	void	setName(const std::string& n);
	void	announce(void);
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name );

#endif