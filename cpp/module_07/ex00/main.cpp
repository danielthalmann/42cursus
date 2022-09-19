
#include <iostream>
#include "whatever.hpp"

void print (int &a, int &b)
{
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << std::endl;
}

void testA(void)
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

}

void testB(void)
{
	int a = 4;
	int b = 2;
	
	print (a, b);

	std::cout << "swap<int>(a, b) " << std::endl;
	swap<int>(a, b);

	print (a, b);

	std::cout << "swap(a, b) " << std::endl;
	swap(a, b);

	print (a, b);

	{
		int &c = min (a, b);
		std::cout << "min (a, b) " << std::endl;
		std::cout << "min is : " << c << std::endl;
		std::cout << std::endl;
	}

	{
		int &c = max (a, b);

		std::cout << "max (a, b) " << std::endl;
		std::cout << "max is : " << c << std::endl;		
		std::cout << std::endl;
	}

}

int main ( void )
{

	testA();
	return (0);
}
