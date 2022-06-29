
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


void testA( void )
{
	std::cout << std::endl << ANSI_COLOR_RED << "TEST A " << ANSI_COLOR_RESET << std::endl << std::endl;

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

void testB( void )
{	
	std::cout << std::endl << ANSI_COLOR_RED << "TEST B " << ANSI_COLOR_RESET << std::endl << std::endl;

	ScavTrap st("Robert");

	st.info();
	st.attack("world");
	st.info();
	st.takeDamage(5);
	st.info();
	st.beRepaired(2);
	st.info();
	st.guardGate();
	st.info();
	st.beRepaired(2);
	st.info();
	st.takeDamage(10);
	st.info();
	st.beRepaired(2);
	st.info();
	st.attack("world 2");
	st.info();

}

int main ( void )
{
	testA();
	testB();
	return (0);
}
