
#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
	if (ac < 2) 
	{
		std::cerr << "Error: wrong number of arguments\n";
		return 1;
	}

	std::string input;
	for (int i = 1; i < ac; ++i) 
	{
		input += av[i];
		if (i < ac - 1)
			input += " ";
	}

	PmergeMe<std::deque<int> > sorter;

	try 
	{
		sorter.sort(input);
		sorter.printContainer();
	}
	catch(const std::exception& e) 
	{
		std::cerr << "Failed.";
		return 1;
	}

	return 0;
}