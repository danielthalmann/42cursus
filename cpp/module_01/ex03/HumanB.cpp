
#include "HumanB.hpp"

HumanB::HumanB() :
	_name("HumanB"),
	_weapon(NULL)
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	std::cout << " est nee" << std::endl;
}

HumanB::HumanB(std::string name) :
	_name(name),
	_weapon(NULL)
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	std::cout << " est nee" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << ANSI_COLOR_GREEN << _name << ANSI_COLOR_RESET;
	std::cout << " meurt" << std::endl;
}

void HumanB::attack( void )
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

void HumanB::setWeapon(Weapon &w)
{
	_weapon = &w;
}
