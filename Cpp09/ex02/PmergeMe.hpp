

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <sstream>
#include <ctime>
#include <iomanip>
/**
 * @brief 
 * 
 * @tparam T the container type 
 */
template <typename T>
class	PmergeMe
{
	private:
		double	execution_time;
		T		sorted_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& lhs);
		~PmergeMe();

		void	sort(const std::string input);
		void	setContainer(const std::string input, T& cont);
		void	fordJhonson(T unsorted_list); 
		void	split(T nums, T& followers, T& leaders);
		void	merge(T unsorted_nums);
		void	getJacobsthalIndices(size_t max, std::vector<int>& order);
		void	printContainer() const;
		void	isNumber(const std::string& input);
		double	getExecutionTime() const;
		size_t	getSize() const;
};

#include "PmergeMe.cpp"

#endif
