
#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	_name = name;
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