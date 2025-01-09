
#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
	private:
		Brain*	brain;
	public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &rhs);
	~Cat();

	void	makeSound() const;
	void	printIdeas() const;
	std::string	getType() const;
};

#endif