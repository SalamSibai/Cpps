
#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat& rhs);

		void		makeSound(void) const;
};

#endif