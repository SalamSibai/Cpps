/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:57:25 by ssibai            #+#    #+#             */
/*   Updated: 2025/05/31 14:03:46 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

std::ostream &operator<<(std::ostream &out, const Data &data)
{
	out << "[";
	out << data.d_id << ", " << data.d_name << "]";
	return (out);
}

int main()
{
	Data*    d;
	d = new Data(123, "test");
	d = Serializer::deserialize(Serializer::serialize(d));
	std::cout << *d << std::endl;

	delete d;
	return (0);
}