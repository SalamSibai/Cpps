
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <climits>
#include <limits>
#include <sstream>
#include <exception>

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
        std::stack<int>    num;
        int                result; 
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& lhs);
        ~RPN();
        
        bool    isOperator(const std::string& token);
        bool    isNumber(const std::string& token);
        int     calculate(const std::string line);
};
// class Peace { 

//         private: 
//              map::<>
//          std::string _name;   
//       ]      public:
//       void validThename(const std::string& name);
//       void getName();
         
        
// }

#endif