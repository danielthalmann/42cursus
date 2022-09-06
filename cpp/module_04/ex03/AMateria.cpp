#include "AMateria.hpp"

#define CLASSNAME "AMateria"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}