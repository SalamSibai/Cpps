/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:12:17 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/14 17:36:11 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> mlist;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " <<mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "normal stack top: " << s.top() << std::endl;

	mlist.push_back(5);
	mlist.push_back(17);
	//std::cout << "top: " <<mlist.top() << std::endl;
	//mlist.pop();
	std::cout << "size: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	//MutantStack<int>::iterator it = mlist.begin();
	//MutantStack<int>::iterator ite = mlist.end();
	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itel = mlist.end();

	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	

	return 0;
}