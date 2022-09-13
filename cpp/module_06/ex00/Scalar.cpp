#include "Scalar.hpp"

#define CLASSNAME "Scalar"

Scalar::Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Scalar::Scalar(Scalar &scalar)
{
	(*this) = (scalar);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Scalar::~Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Scalar &Scalar::operator=(const Scalar &scalar)
{
	(void) scalar;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

void Scalar::print( void )
{
	std::cout << "char:" << this->toChar() << std::endl;
	std::cout << "int:" << this->toInt() << std::endl;
	std::cout << "float:" << this->toFloat() << std::endl;
	std::cout << "double:" << this->toDouble() << std::endl;
}


