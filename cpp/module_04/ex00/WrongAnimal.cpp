#include "WrongAnimal.hpp"

#define CLASSNAME "WrongAnimal"

WrongAnimal::WrongAnimal()
{
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &wronganimal)
{
	(void) wronganimal;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	(void) wronganimal;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animal Muted" << std::endl;
}