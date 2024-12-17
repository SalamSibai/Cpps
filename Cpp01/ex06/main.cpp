
#include "Harl.h"

int main(int ac, char **av)
{
    Harl harl;

	if (ac != 2)
		std::cout << "Wrong number of parameters." << std::endl;
	else
	{
		std::cout << "[" << av[1] << "]" << std::endl;
		harl.complain(av[1]);
	}
    return 0;
}