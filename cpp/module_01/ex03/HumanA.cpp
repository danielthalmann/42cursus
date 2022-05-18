
#include "HumanA.hpp"

HumanA::HumanA() :
	_name("HumanA"),
	_weapon(NULL)
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	std::cout << " est nee" << std::endl;
}

HumanA::HumanA(std::string name, Weapon &w) : 
	_name(name),
	_weapon(&w)
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	std::cout << " est nee" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	std::cout << " meurt" << std::endl;
}

void HumanA::attack( void )
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	if (_weapon)
	{
		std::cout << " attaque avec ";
		std::cout << ANSI_COLOR_RED << _weapon->getType() << ANSI_COLOR_RESET << std::endl;
	}
	else
		std::cout << " n'a rien pour frapper ";
}

void HumanA::setWeapon(Weapon &w)
{
	_weapon = &w;
}
