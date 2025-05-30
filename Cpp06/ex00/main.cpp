
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    (void) av;
    if (ac != 2)
        std::cout << "wrong number o arguments";
    else
        ScalarConverter::convert(av[1]);
    return 0;
}