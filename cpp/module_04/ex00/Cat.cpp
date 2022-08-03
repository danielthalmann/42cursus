#include "Cat.hpp"

#define CLASSNAME "Cat"

Cat::Cat()
{
	std::cout << "Construct " << CLASSNAME << std::endl;
}

Cat::Cat(Cat &cat) : Animal (cat)
{
	(void) cat;
	std::cout << "Copy Construct " << CLASSNAME << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor " << CLASSNAME << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	(void) cat;
	std::cout << "Operator Equal " << CLASSNAME << std::endl;
	return (*this);
}