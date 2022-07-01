
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


void testA( void )
{
	std::cout << std::endl << ANSI_COLOR_RED << "TEST A (Diamon)" << ANSI_COLOR_RESET << std::endl << std::endl;

	DiamondTrap dt("Daniel");

	dt.info();
	dt.attack("world");
	dt.info();
	dt.takeDamage(5);
	dt.info();
	dt.beRepaired(2);
	dt.info();
	dt.highFiveGuys();
	dt.info();
	dt.whoAmI();
	std::cout << std::endl;

}

void testB( void )
{
	std::cout << std::endl << ANSI_COLOR_RED << "TEST B (Diamon with ptr)" << ANSI_COLOR_RESET << std::endl << std::endl;

	DiamondTrap dt("Bernard");

	FragTrap *dtp = &dt;

	dtp->info();
	dtp->attack("world");
	dtp->info();
	dtp->takeDamage(5);
	dtp->info();
	dtp->beRepaired(2);
	dtp->info();
	dtp->highFiveGuys();
	dtp->info();
	dt.whoAmI();
	std::cout << std::endl;
}

int main ( void )
{
	testA();
	testB();
	return (0);
}
