#include "Animal.hpp"

#define CLASSNAME "Animal"

Animal::Animal()
{
	std::cout << "Construct " << CLASSNAME << std::endl;
}

Animal::Animal(Animal &animal)
{
	(void) animal;
	std::cout << "Copy Construct " << CLASSNAME << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor " << CLASSNAME << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	(void) animal;
	std::cout << "Operator Equal " << CLASSNAME << std::endl;
	return (*this);
}