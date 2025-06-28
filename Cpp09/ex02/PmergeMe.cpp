
#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : execution_time(0) {}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other) 
		: execution_time(other.execution_time), sorted_list(other.sorted_list) {}

template<typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& lhs)
{
	if (this != &lhs)
	{
		execution_time = lhs.execution_time;
		sorted_list = lhs.sorted_list;
	}
	return *this;
}

template<typename T>
PmergeMe<T>::~PmergeMe() {}


template <typename T>
void PmergeMe<T>::printContainer() const
{
	typename T::const_iterator it = sorted_list.begin();
	while (it != sorted_list.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void	PmergeMe<T>::setContainer(const std::string input, T& cont)
{
	
	std::stringstream ss(input);
	std::string token;

	while (ss >> token)
	{
		try 
		{
			isNumber(token);
			long num = std::atol(token.c_str());
			if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() 
					|| num < 0)
				throw std::runtime_error("Error: invalid number\n");

			cont.push_back(static_cast<int>(num));
		}
		catch (const std::exception& e)
		{
			throw;
		}
	}
}

template<typename T>
void	PmergeMe<T>::sort(const std::string input)
{
	T	in_container;

	try
	{
		setContainer(input, in_container);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Container can't be setup\n";
		throw;
	}

	fordJhonson(in_container);
}

template<typename T>
void	PmergeMe<T>::fordJhonson(T& unsorted_list)
{
	(void) unsorted_list;
}

template<typename T>
void	PmergeMe<T>::isNumber(const std::string& input)
{
	if (input.empty())
		throw (std::runtime_error("Error: Empty string!\n"));
	for (std::size_t i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i])) 
			throw (std::runtime_error("Error: not numbers!\n"));
	}
}

// template class PmergeMe<std::vector<int> >;
// template class PmergeMe<std::deque<int> >;