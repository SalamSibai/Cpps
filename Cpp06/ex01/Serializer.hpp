/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:00 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/31 14:05:41 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{
	int         d_id;
	std::string d_name;
	Data(int	id, std::string	n) : d_id(id), d_name(n) {}
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const	Serializer& lhs);
	~Serializer();
public:
	static	uintptr_t	serialize(Data			*ptr);
	static	Data*		deserialize(uintptr_t	raw);
};

#endif