#include "AAnimal.hpp"

#define CLASSNAME "AAnimal"

AAnimal::~AAnimal()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}