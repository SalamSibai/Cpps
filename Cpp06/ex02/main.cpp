/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:25:39 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/02 20:22:37 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include	"Base.hpp"
#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"
#include	<cstdlib> 
#include	<ctime>

Base*	generate()
{
	std::srand(std::time(NULL));
	int	r = rand() % 3;

	switch (r)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
		default:
			return (nullptr);
	}
}

void	identify(Base* p)
{
	std::cout << "Identify with ptr:\n";
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C\n";
}

void	identify(Base& p)
{

	std::cout << "Identify with reference:\n";
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Type: A\n";
		return ;
	} 
	catch (std::exception& e)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << "type: B\n";
			return ;
		}
		catch (std::exception& e) 
		{
			std::cout << "type: C\n";
			return ;
		}
	}
}

int main()
{
	A a;
	B b;
	C c;

	identify(a);
	identify(c);
	identify(b);
	identify(a);

	std::cout << "------\n";

	identify(&b);
	identify(&c);
	identify(&a);
	identify(&b);

	std::cout << "-------\n";

	std::srand(std::time(NULL));
	Base *base;
	for (int i = 0; i < 5; i++)
	{
		base = generate();
		identify(base);
		identify(*base);
		delete (base);
		std::cout << "--\n";
	}
	return 0;
}