#include "Dog.hpp"

#define CLASSNAME "Dog"

Dog::Dog()
{
	_brain = new Brain();
	_type = CLASSNAME;
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Dog::Dog(Dog &dog) : Animal(dog)
{
	_type = dog._type;
	_brain = dog._brain;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	(void) dog;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Wouafff !" << std::endl;
}