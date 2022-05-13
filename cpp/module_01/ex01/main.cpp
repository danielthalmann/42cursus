
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#define NB_ZOMBIE 5

int main ( void )
{

	Zombie *z = zombieHorde(NB_ZOMBIE, "daniel");

	for (int i = 0; i < NB_ZOMBIE; i++)
	{
		z->announce();
	}
	
	delete [] z;	

}
