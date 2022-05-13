
#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
	std::cout << "Destruction de l'arme" << std::endl;
}

void Weapon::setType( std::string t )
{
	_type = t;
}

std::string Weapon::getType( void )
{
	return _type;
}