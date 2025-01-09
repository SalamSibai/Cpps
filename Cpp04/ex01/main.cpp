

#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	const Animal* meta[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	
	for (int i=0; i < 4; i++)
	{
			delete meta[i];
	}
	Dog basic;
	{
		basic.printIdeas();
		Dog tmp (basic);
		tmp.printIdeas();
		basic.printIdeas();
	}
	Animal *tmp;
	tmp = new Dog;
	std::cout << tmp->getType() << std::endl;

	Animal *city(tmp);
	city->makeSound();
	tmp->makeSound();
	delete tmp;

	Cat cat;
	cat.makeSound();
	Cat copycat = cat;
	copycat.makeSound();
}
