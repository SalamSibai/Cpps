/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:03:42 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/14 15:57:58 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <set>
#include <limits>

class Span
{
	private:
		unsigned int	N;
		std::set<int>	set;
	protected:
		class CapacityFullException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		class EmptySetException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		class NoSpanCalculatedException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
	public:
		Span(const int n);
		Span(const Span& other);
		Span& operator=(const Span& lhs);
		~Span();
			
		std::set<int>	getSet() const;
		int		getN()	const;
		void    addNumber(int		num);
		void	addMany(const std::set<int>&	to_add);
		int		shortestSpan();
		int		largestSpan();
};

std::ostream&	operator<<(std::ostream& os, Span& span);

#endif