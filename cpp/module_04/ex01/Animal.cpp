#include "Animal.hpp"

#define CLASSNAME "Animal"

Animal::Animal()
{
	_type = CLASSNAME;
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Animal::Animal(Animal &animal)
{
	_type = animal._type;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Animal::~Animal()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	(void) animal;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (_type);
}

void Animal::makeSound(void) const
{
	std::cout << "Muted" << std::endl;
}