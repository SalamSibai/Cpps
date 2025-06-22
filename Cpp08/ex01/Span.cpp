/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:37:45 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/22 09:51:54 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span(const int n) : N(n) {}

Span::Span(const Span& other) : N(other.getN()), set(other.getSet()) {}

Span& Span::operator=(const Span& lhs)
{
	if (this != &lhs)
	{
		N = lhs.getN();
		set = lhs.getSet();
	}
	return *this;
}

Span::~Span() {}

int Span::getN() const {return N;}

std::set<int>	Span::getSet() const
{
	return set;
}

void    Span::addNumber(int   n)
{
	if (set.size() >= N)
		throw CapacityFullException();
	set.insert(n);
}

void	Span::addMany(const std::set<int>&	to_add)
{
	if (to_add.size() > N - set.size())
		throw CapacityFullException();
	set.insert(to_add.begin(), to_add.end());
}

int		Span::shortestSpan()
{
	if (set.empty())
		throw	EmptySetException();
	else if (set.size() == 1)
		throw	NoSpanCalculatedException();
	
	int	min_span = INT_MAX;
	std::set<int>::iterator prev = set.begin();
	std::set<int>::iterator curr = std::next(prev);	//std::next() shockingly, is also cpp11
													//instead: curr = prev++;
	while (curr != set.end())
	{
		int diff = *curr - *prev;
		if (diff < min_span)
			min_span = diff;
		prev = curr;
		curr ++;
	}
	return min_span;
}

int		Span::largestSpan()
{
	if (set.empty())
		throw	EmptySetException();
	else if (set.size() == 1)
		throw	NoSpanCalculatedException();
	return (*set.rbegin()) - (*set.begin());
}

const char*		Span::NoSpanCalculatedException::what()	const throw()
{
	return ("Can't calculate span.\n");
}

const char*		Span::EmptySetException::what()	const throw()
{
	return ("Set is empty.\n");
}

const char* 	Span::CapacityFullException::what() const throw()
{
	return ("At full capacity.\n");
}

std::ostream&	operator<<(std::ostream& os, Span& span)
{
	std::set<int>	s = span.getSet();
	std::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		os << *it << " ";
		it ++;	
	}
	os << std::endl;
	return os;
}
