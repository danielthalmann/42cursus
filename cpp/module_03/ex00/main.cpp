
#include <iostream>
#include "ClapTrap.hpp"


void testA( void )
{
	ClapTrap ct("Daniel");
	

	ct.info();
	ct.attack("world");
	ct.info();
	ct.takeDamage(5);
	ct.info();
	ct.beRepaired(2);

	for (size_t i = 0; i < 9; i++)
	{
		ct.attack("world");
	}
	ct.info();	
	ct.beRepaired(2);
	ct.info();
	ct.takeDamage(10);
	ct.info();
	ct.beRepaired(2);
	ct.info();
	ct.attack("world 2");
	ct.info();

}

int main ( void )
{
	testA();
	return (0);
}
