
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


void testA( void )
{
	std::cout << std::endl << ANSI_COLOR_RED << "TEST A (FragTrap)" << ANSI_COLOR_RESET << std::endl << std::endl;

	FragTrap ft("Daniel");

	ft.info();
	ft.attack("world");
	ft.info();
	ft.takeDamage(5);
	ft.info();
	ft.beRepaired(2);
	ft.info();
	ft.highFiveGuys();
	std::cout << std::endl;

}

void testB( void )
{
	std::cout << std::endl << ANSI_COLOR_RED << "TEST B (FragTrap with ptr)" << ANSI_COLOR_RESET << std::endl << std::endl;

	FragTrap ft("Bernard");

	FragTrap *ftp = &ft;

	ftp->info();
	ftp->attack("world");
	ftp->info();
	ftp->takeDamage(5);
	ftp->info();
	ftp->beRepaired(2);
	ftp->info();
	ftp->highFiveGuys();
	std::cout << std::endl;
}

int main ( void )
{
	testA();
	testB();
	return (0);
}
