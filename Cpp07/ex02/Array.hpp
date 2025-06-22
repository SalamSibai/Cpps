/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:05:58 by ssibai            #+#    #+#             */
/*   Updated: 2025/06/10 17:52:08 by ssibai           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP   
#define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
private:
	T*				arr;
	unsigned int	length;
protected:
	class OutOfBoundsException : public std::exception 
	{
		public:
			const char* what() const throw()	{return ("out of bounds!\n");}
	};
public:
	Array() : arr(NULL), length(0) {}
	Array(unsigned int n) : arr(new T[n]), length(n) {}
	
	Array(const Array& other) : arr(NULL), length(0)
	{
		if (this != &other)
		{
			arr = new T[other.length];
			length = other.length;
			for (int i = 0; i < length; i++)
				arr[i] = other.arr[i];
		}
	}

	Array&	operator=(const	Array& lhs)
	{
		if (this != &lhs)
		{
			if (arr)
				delete[]	arr;
			length = 		lhs.length;
			arr = 		new T[length];
			for (int i = 0; i < length; i++)
				arr[i] = lhs.arr[i];
		}
		return *this;
	}

	T	operator[](unsigned int index) const
	{
		if (index >= length)
			throw OutOfBoundsException();
		return (arr[index]);
	}

	T&	operator[](unsigned int index)
	{
		if (index >= length)
			throw OutOfBoundsException();
		return (arr[index]);
	}

	~Array()
	{
		if (arr)
			delete[] arr;
	}

	unsigned int size()	{ return length; }
	
};


#endif