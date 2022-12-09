#include "AMateria.hpp"

#define CLASSNAME "AMateria"

AMateria::AMateria(std::string const &type) : _type(type)
{
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

AMateria::~AMateria()
{
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

std::string const &AMateria::getType() const
{
	return _type;
}