#include "Dog.hpp"

#define CLASSNAME "Dog"

Dog::Dog()
{
	std::cout << "Construct " << CLASSNAME << std::endl;
}

Dog::Dog(Dog &dog) : Animal(dog)
{
	(void) dog;
	std::cout << "Copy Construct " << CLASSNAME << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor " << CLASSNAME << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	(void) dog;
	std::cout << "Operator Equal " << CLASSNAME << std::endl;
	return (*this);
}