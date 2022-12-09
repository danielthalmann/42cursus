
#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main ( void )
{
	Base *b;

	std::srand(std::time(NULL));

	for (size_t i = 0; i < 10; i++)
	{
		b = Base::generate();
		Base::identify(b);
		Base::identify(*b);
		std::cout << std::endl;
		delete b;
	}
	
	
	return (0);
}
