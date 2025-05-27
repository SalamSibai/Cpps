
#include "Brain.h"

Brain::Brain()
{
	std::cout << "Brain constructor is called." << std::endl;
	ideas = new std::string[100];
	for(int i = 0; i < 100; i++)
		ideas[i] = "Light Bulb!";

}

Brain::Brain(const Brain &other)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i] + "... copying my ideas?";
}

Brain& Brain::operator=(const Brain &rhs)
{
	delete [] ideas;
	ideas = new std::string[100];
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

std::string*	Brain::getIdeas() const
{
	return (ideas);
}

Brain::~Brain()
{
	std::cout << "Destructor of BRAIN is called" << std::endl;
	delete[] ideas;
}