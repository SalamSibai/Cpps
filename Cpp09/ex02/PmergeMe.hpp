

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <sstream>


/**
 * @brief 
 * 
 * @tparam T the container type 
 */
template <typename T>
class	PmergeMe
{
	private:
		float	execution_time;
		T		sorted_list;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& lhs);
		~PmergeMe();

		void	sort(const std::string input);
		void	setContainer(const std::string input, T& cont);
		void	fordJhonson(T& unsorted_list);
		void	printContainer() const;
		//find insertion order for 
};

void	isNumber(const std::string& input);

#endif
