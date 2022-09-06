#include "Ice.hpp"

#define CLASSNAME "Ice"

Ice::Ice() : AMateria("ice")
{
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Ice::Ice(Ice &ice) : AMateria("ice")
{
	*this = ice;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Ice::~Ice()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Ice &Ice::operator=(const Ice &ice)
{
	(void) ice;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
