#include "Brain.hpp"

#define CLASSNAME "Brain"

Brain::Brain()
{
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Brain::Brain(Brain &brain)
{
	(void) brain;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Brain::~Brain()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	(void) brain;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}