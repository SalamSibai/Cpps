/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:05 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/31 14:12:06 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) {*this = other;}
Serializer& Serializer::operator=(const Serializer& lhs) 
{ 
	(void) lhs; 
	return *this;
}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));	
}

Data*	Serializer::deserialize(uintptr_t	raw)
{
	return (reinterpret_cast<Data*>(raw));	 
}

