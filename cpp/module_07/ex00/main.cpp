
#include <iostream>
#include "whatever.hpp"

void print (int &a, int &b)
{
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
}

int main ( void )
{

	int a = 5;
	int b = 9;
	

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




	return (0);
}
