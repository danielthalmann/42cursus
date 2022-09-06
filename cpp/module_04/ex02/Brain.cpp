#include "Brain.hpp"

#define CLASSNAME "Brain"

Brain::Brain()
{
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Brain::Brain(Brain &brain)
{
	*this = brain;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Brain::~Brain()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	for (int i = 0; i < Brain::sizeOfIdeas; i++)
		this->_ideas[i] = brain._ideas[i];
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

std::string *Brain::getIdeas()
{
	return _ideas;
}