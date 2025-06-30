
#include "PmergeMe.hpp"

std::string trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";

	std::size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}


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
		std::string token = trim(av[i]);
		if (!token.empty())
		{
			input += token;
			if (i < ac - 1)
			input += " ";
		}
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