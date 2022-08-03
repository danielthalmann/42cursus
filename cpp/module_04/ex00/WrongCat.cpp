#include "WrongCat.hpp"

#define CLASSNAME "WrongCat"

WrongCat::WrongCat()
{
	_type = CLASSNAME;
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

WrongCat::WrongCat(WrongCat &wrongcat) : WrongAnimal(wrongcat)
{
	_type = wrongcat._type;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	(void) wrongcat;
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Miaou !" << std::endl;
}