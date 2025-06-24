/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:20:55 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/24 20:27:25 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <climits>
#include <limits>
#include <sstream>
#include <exception>
#include <cstdlib>

/**
How it wokrs:

You push numbers into a stack
-   when you find an operator,
	you pop from the stack,
-   the first number will be the lhs,
	the second will be the rhs
-   execute the operator on the numbers
	and store result

 */
class RPN
{
	private:
		std::stack<int>			nums;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& lhs);
		~RPN();
		
		bool	isOperator(const std::string& token);
		bool	isNumber(const std::string& token);
		void	getResult(const std::string line);
		void	calculate(char	token);
};

#endif