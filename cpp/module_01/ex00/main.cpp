
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main ( void )
{

	Zombie *z = newZombie("daniel");
	z->announce();

	randomChump("Aliend");

	delete z;	

}
