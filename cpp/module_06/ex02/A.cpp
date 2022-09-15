#include "A.hpp"

#define CLASSNAME "A"

A::~A()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}
