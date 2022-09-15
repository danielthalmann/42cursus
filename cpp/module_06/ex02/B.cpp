#include "B.hpp"

#define CLASSNAME "B"

B::~B()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}
