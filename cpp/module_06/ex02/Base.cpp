#include "Base.hpp"

#define CLASSNAME "Base"

Base::~Base()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Base *Base::generate(void)
{
	std::
}

void Base::identify(Base* p)
{

}

void Base::identify(Base& p)
{

}
