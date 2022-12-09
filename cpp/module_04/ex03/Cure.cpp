#include "Cure.hpp"

#define CLASSNAME "Cure"

Cure::Cure() : AMateria("cure")
{
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Cure::Cure(Cure &cure) : AMateria("cure")
{
	*this = cure;
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Cure::~Cure()
{
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Cure &Cure::operator=(const Cure &cure)
{
	(void) cure;
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
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