
#include <iostream>
#include "Fixed.hpp"


void testA( void )
{
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
