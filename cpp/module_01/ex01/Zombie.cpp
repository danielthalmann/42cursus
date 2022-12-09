
#include "Zombie.hpp"

Zombie::Zombie()
{
}

/**
 * @brief Construct a new Zombie:: Zombie object
 * le set name écrit de la manière suivante ne peut 
 * s'appliquer que sur le constructeur : _name (name)
 * 
 * @param name 
 */
Zombie::Zombie(std::string name): _name (name)
{
}

Zombie::~Zombie()
{
	std::cout << "Le zombie a perdu tous ces membres" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name;
	std::cout << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name )
{
	_name = name;
}