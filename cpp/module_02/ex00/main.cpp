
#include <iostream>
#include "Fixed.hpp"
#include "colors.hpp"


void testA( void )
{
	std::cout << ANSI_COLOR_BLUE << "test A" << ANSI_COLOR_RESET << std::endl;

	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

void testB( void )
{
	std::cout << ANSI_COLOR_BLUE << "test B" << ANSI_COLOR_RESET << std::endl;

	Fixed a;
	a.setRawBits(42);
	Fixed b( a );
	Fixed c;
	c = b;
	b.setRawBits(24);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}


int main ( void )
{
	
	std::cout << std::endl << std::endl;
 	testA();
	std::cout << std::endl << std::endl;
	testB();
	std::cout << std::endl << std::endl;

	return (0);
}
