
#include <iostream>
#include "Fixed.hpp"
#include "colors.hpp"


void testA( void )
{

	std::cout << ANSI_COLOR_BLUE << "test A" << ANSI_COLOR_RESET << std::endl;

	Fixed       a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << ANSI_COLOR_BLUE << "a" << ANSI_COLOR_RESET << " is " << a << std::endl;
	std::cout << ANSI_COLOR_BLUE << "b" << ANSI_COLOR_RESET << " is " << b << std::endl;
	std::cout << ANSI_COLOR_BLUE << "c" << ANSI_COLOR_RESET << " is " << c << std::endl;
	std::cout << ANSI_COLOR_BLUE << "d" << ANSI_COLOR_RESET << " is " << d << std::endl;

	std::cout << ANSI_COLOR_BLUE << "a" << ANSI_COLOR_RESET << " is " << a.toInt() << " as integer" << std::endl;
	std::cout << ANSI_COLOR_BLUE << "b" << ANSI_COLOR_RESET << " is " << b.toInt() << " as integer" << std::endl;
	std::cout << ANSI_COLOR_BLUE << "c" << ANSI_COLOR_RESET << " is " << c.toInt() << " as integer" << std::endl;
	std::cout << ANSI_COLOR_BLUE << "d" << ANSI_COLOR_RESET << " is " << d.toInt() << " as integer" << std::endl;
}

void testB( void )
{

	std::cout << ANSI_COLOR_BLUE << "test B" << ANSI_COLOR_RESET << std::endl;

	Fixed       a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << ANSI_COLOR_BLUE << "a" << ANSI_COLOR_RESET << " is " << a.toFloat() << " as float" << std::endl;
	std::cout << ANSI_COLOR_BLUE << "b" << ANSI_COLOR_RESET << " is " << b.toFloat() << " as float" << std::endl;
	std::cout << ANSI_COLOR_BLUE << "c" << ANSI_COLOR_RESET << " is " << c.toFloat() << " as float" << std::endl;
	std::cout << ANSI_COLOR_BLUE << "d" << ANSI_COLOR_RESET << " is " << d.toFloat() << " as float" << std::endl;
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
