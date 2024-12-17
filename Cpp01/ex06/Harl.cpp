
#include <iostream>
#include "Harl.h"

void	Harl::complain(std::string level)
{
	std::string  str_arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*funptr[4])();
	funptr[0]= &Harl::debug;
	funptr[1]= &Harl::info;
	funptr[2]= &Harl::warning;
	funptr[3]= &Harl::error;

	int	i = 0;
	while (i < 4 && str_arr[i].compare(level.c_str()) != 0)
		i++;
	
	switch(i)
	{
		case 0:
			(this->*funptr[0])();
			break;
		case 1:
			(this->*funptr[1])();
			break;
		case 2:
			(this->*funptr[2])();
			break;
		case 3:
			(this->*funptr[3])();
			break;
		default:
			std::cout << "doesn't matter really.." << std::endl; 
	}
}

void	Harl::debug(void)
{
	std::cout << "I AM DEBUGGING!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I AM GIVING INFO!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I AM GIVING WARGNING!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "I AM ERROR!" << std::endl;
}