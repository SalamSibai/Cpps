
#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

/**
 * @brief The reason why ideas is a pointer,
 * 			is because we want to return a pointer
 * 			to the first element in the array in 
 * 			"getIdeas()" method.
 */
class Brain
{
	private:
	std::string	*ideas;

	public:
	Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain &rhs);
	virtual ~Brain();

	std::string*	getIdeas() const;
};

#endif
