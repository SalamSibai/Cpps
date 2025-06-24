/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:20:51 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/24 20:25:43 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : result(other.result) {}

RPN&	RPN::operator=(const RPN& lhs)
{
	if (this != &lhs)
	{
		num = lhs.num;
		result = lhs.result;
	}
	return (*this);
}

bool	RPN::isOperator(const std::string& token)
{
	return token == "+" || token == "-" 
			|| token == "/" || token == "*";
}

bool	RPN::isNumber(const std::string& token)
{
	if (token.empty())  
		return false;
	for (std::size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(token[i])) 
			return false;
	}
	return true;
}

void		RPN::getResult(const std::string line)
{
	std::stringstream	ss(line);
	std::string			token;

	while (ss >> token)
	{
		if (isNumber(token))
		{
			long num = std::atol(token.c_str());
			if (num > INT_MAX || num < INT_MIN)
				throw std::runtime_error("Error: invalid number\n");
			nums.push(num);
		}
		else if (isOperator(token))
		{
			if (nums.size() < 2)
				throw std::runtime_error("Error: Invalid RPN");
			try
			{
				calculate(token);
			}
			catch (const std::exception& e)
			{
				return ;
			}
		}
		else
			throw std::runtime_error("Error: Invalid RPN");
	}
	if (nums.size() != 1)
		throw std::runtime_error("Error: invalid RPN expression");
	std::cout << nums.top();
}

void	std::calculate(char token)
{
	long	val;
	int lhs = nums.top(); nums.pop();
	int rhs = nums.top(); nums.pop();
	switch(token)
	{
		case '+':
			val = rhs + lhs;
			break;

		case '-':
			val = rhs - lhs;
			break;
			
		case '*':
			val = rhs * lhs;
			break;
			
		case '/':
			if (rhs == 0)
				throw std::runtime_error("Error: division by zero!\n")
			val = rhs / lhs;
			break;
		default:
			throw std::runtime_error("Error: invalid operator");
	}

	if (result > INT_MAX || result < INT_MIN)
		throw std::runtime_error("Error: invalid value\n");
	nums.push(static_cast<int>(val));
}
