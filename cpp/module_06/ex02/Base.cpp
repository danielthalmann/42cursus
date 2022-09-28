#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define CLASSNAME "Base"

Base::~Base()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Base *Base::generate(void)
{
	int r = std::rand();
	r = r % 3;
	switch(r)
	{
		case 0:
			std::cout << "generate object " << "\x1b[31m" << "A" << "\x1b[0m" << std::endl;
			return new A();
		break;
		case 1:
			std::cout << "generate object " << "\x1b[34m" << "B" << "\x1b[0m" << std::endl;
			return new B();
		break;
	}
	std::cout << "generate object " << "\x1b[32m" << "C" << "\x1b[0m" << std::endl;
	return new C();
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "pointer contain object " << "\x1b[31m" << "A" << "\x1b[0m" << std::endl;

	if (dynamic_cast<B *>(p))
		std::cout << "pointer contain object " << "\x1b[34m" << "B" << "\x1b[0m" << std::endl;
	
	if (dynamic_cast<C *>(p))
		std::cout << "pointer contain object " << "\x1b[32m" << "C" << "\x1b[0m" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "reference contain object " << "\x1b[31m" << "A" << "\x1b[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		#ifdef DEBUG
			std::cerr << e.what() << std::endl;
		#endif
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "reference contain object " << "\x1b[34m" << "B" << "\x1b[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		#ifdef DEBUG
			std::cerr << e.what() << std::endl;
		#endif
	}	

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "reference contain object " << "\x1b[32m" << "C" << "\x1b[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		#ifdef DEBUG
			std::cerr << e.what() << std::endl;
		#endif
	}
}
