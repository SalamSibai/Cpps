/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:37:09 by ssibai            #+#    #+#             */
/*   Updated: 2025/07/01 21:37:40 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
PmergeMe<T>::~PmergeMe() { sorted_list.clear(); }


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

template <typename T>
double PmergeMe<T>::getExecutionTime() const
{
	return execution_time / 1000000.0;
}

template <typename T>
size_t PmergeMe<T>::getSize() const
{
	return sorted_list.size();
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
	if (cont.empty())
		throw std::runtime_error("Error: container is empty after parsing input.\n");
}

template<typename T>
void	PmergeMe<T>::sort(const std::string input)
{
	T	in_container;
	sorted_list.clear();

	try
	{
		setContainer(input, in_container);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "Error: Container can't be setup\n";
		throw;
	}

	clock_t start = clock();
	fordJhonson(in_container);
	clock_t end = clock();
	execution_time = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

/**
 * @brief 
 * 
 * @tparam T 				container type
 * @param unsorted_list 	

	algorithm:
		1)	Separate the list into pairs.
		2)	Create a "leaders" container, where the largest
			element of every pair is placed, in its correct spot
			(accumulates each time)
 */
template<typename T>
void	PmergeMe<T>::fordJhonson(T unsorted_list)
{
	if (unsorted_list.size() <= 2)
	{
		if (unsorted_list.size() == 1)
			sorted_list.push_back(unsorted_list[0]);
		else
		{
			if (unsorted_list[0] > unsorted_list[1])
			{
				sorted_list.push_back(unsorted_list[1]);
				sorted_list.push_back(unsorted_list[0]);
			}
			else
			{
				sorted_list.push_back(unsorted_list[0]);
				sorted_list.push_back(unsorted_list[1]);
			}
		}
		return ;
	}
	T	followers, leaders;
	split(unsorted_list, followers, leaders);
	fordJhonson(leaders);
	merge(followers);
}

/**
 * @brief			keeps splitting elements until the size is 2
 *
 * @tparam T 
 * @param nums 
 */
template<typename T>
void	PmergeMe<T>::split(T nums, T& followers, T& leaders)
{
	size_t i = 0;
	while (i + 1 < nums.size())
	{
		if (nums[i] <= nums[i + 1])
		{
			leaders.push_back(nums[i]);
			followers.push_back(nums[i + 1]);
		}
		else
		{
			leaders.push_back(nums[i + 1]);
			followers.push_back(nums[i]);
		}
		i += 2;
	}

	if (i < nums.size())
		followers.push_back(nums[i]);
}

/**
 * @brief	Merges sorted nums and unsorted nums, resulting in a sorted list.
 * 
 * @tparam T 
 * @param sorted_nums 
 * @param unsorted_nums 

			based on the size of unsorted nums, find and calculate the
			order which the numbers need to be inserted.

 */
template<typename T>
void	PmergeMe<T>::merge(T unsorted_nums)

{
	std::vector<int> order;

	getJacobsthalIndices(unsorted_nums.size(), order);

	for (std::size_t i = 0; i < order.size(); ++i)
	{
		if (static_cast<std::size_t>(order[i]) >= unsorted_nums.size())
			continue;

		typename T::iterator pos = std::upper_bound(
			sorted_list.begin(), 
			sorted_list.end(), 
			unsorted_nums[order[i]]
		);
		sorted_list.insert(pos, unsorted_nums[order[i]]);
	}
}

/**
 * @brief 	returns the order in which the numbers should be inserted
 * 
 * @tparam T 
 * @param max 
 * @param order 

 				J(n)=J(n−1)+2J(n−2)
 */
template<typename T>
void PmergeMe<T>::getJacobsthalIndices(size_t max, std::vector<int>& order)
{
	if (max == 0)
		return;

	std::vector<bool> added(max, false); 

	order.push_back(0);
	added[0] = true;

	std::vector<int> jacob_indices;
	size_t j1 = 1;
	size_t j2 = 0;
	while (j1 < max)
	{
		jacob_indices.push_back(j1);
		size_t next = j1 + 2 * j2;
		j2 = j1;
		j1 = next;
	}

	for (size_t i = 0; i < jacob_indices.size(); ++i)
	{
		int idx = jacob_indices[i];
		if (idx < static_cast<int>(max) && !added[idx])
		{
			order.push_back(idx);
			added[idx] = true;
		}
	}

	for (size_t i = 0; i < max; ++i)
	{
		if (!added[i])
			order.push_back(i);
	}
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

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;