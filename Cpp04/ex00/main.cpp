
#include "Animal.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Dog.h"
#include "Cat.h"

int main()
{

	// Animal a;
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	const WrongAnimal* c = new WrongCat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();
	c->makeSound();
	// delete meta;
	// delete i;
	// delete j;
	delete c;

return 0;
}
