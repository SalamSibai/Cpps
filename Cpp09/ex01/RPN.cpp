
#include "RPN.hpp"

RPN::RPN() : result(INT_MAX) {}

RPN::RPN(const RPN& other) : result(other.result) {}

RPN& RPN::operator=(const RPN& lhs)
{
    if (this != &RPN)
    {
        num = lhs.num;
        result = lhs.result;
    }
    return (*this);
}

bool    RPN::isOperator(const std::string& token)
{
    return token == "+" || token == "-" 
            || token == "/" || token == "*";
}

bool    RPN::isNumber(const std::string& token)
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

int     RPN::calculate(const std::string line)
{
    std::stringstream   ss(input);
    std::string         token;

    while (ss >> token)
    {
        if (isNumber(token))
        {
            long num = std::atol(token.c_str());
            if (num > INT_MAX || num < INT_MIN)
                throw std::runtime_error("Error: invalid number\n");
            
        }
        else if (isOperator(token))
        {
            if (nums.size() < 2)
			    throw std::runtime_error("Error: Invalid RPN");
            else
            {

            }
        }
        else
        	throw std::runtime_error("Error: Invalid RPN");
    }
}