
#include <iostream>
#include "Fixed.hpp"
#include "colors.hpp"

void testA( void )
{
	Fixed       a;
	Fixed       c;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2.0f ) );

	std::cout << "a   is " << ANSI_COLOR_BLUE << a << ANSI_COLOR_RESET << std::endl;
	std::cout << "++a is " << ANSI_COLOR_BLUE << ++a << ANSI_COLOR_RESET << std::endl;
	std::cout << "a   is " << ANSI_COLOR_BLUE << a << ANSI_COLOR_RESET << std::endl;
	c = a;
	std::cout << "c   is " << ANSI_COLOR_BLUE << c << ANSI_COLOR_RESET << std::endl;
	std::cout << "a++ is " << ANSI_COLOR_BLUE << a++ << ANSI_COLOR_RESET << std::endl;
	std::cout << "a   is " << ANSI_COLOR_BLUE << a << ANSI_COLOR_RESET << std::endl;

	std::cout << "b   is " << ANSI_COLOR_BLUE << b << ANSI_COLOR_RESET << std::endl;
	std::cout << "max is " << ANSI_COLOR_BLUE << Fixed::max( a, b ) << ANSI_COLOR_RESET << std::endl;
}

int main ( void )
{
	
	std::cout << std::endl << std::endl;
 	testA();
	std::cout << std::endl << std::endl;

	return (0);
}
