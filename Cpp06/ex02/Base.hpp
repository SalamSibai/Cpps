/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:17:29 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/02 20:12:21 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef	BASE_HPP
#define	BASE_HPP

#include <iostream>

class	Base
{
public:
	virtual	~Base() {std::cout << "Base destructor called.\n";}
};

#endif