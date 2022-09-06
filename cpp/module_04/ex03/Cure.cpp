#include "Cure.hpp"

#define CLASSNAME "Cure"

Cure::Cure() : AMateria("cure")
{
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Cure::Cure(Cure &cure) : AMateria("cure")
{
	*this = cure;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Cure::~Cure()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Cure &Cure::operator=(const Cure &cure)
{
	(void) cure;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}