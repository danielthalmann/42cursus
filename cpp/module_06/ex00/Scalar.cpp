#include "Scalar.hpp"

#define CLASSNAME "Scalar"

Scalar::Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_impossible = false;
	_overflow = false;
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

bool 	Scalar::isOverflow(void) const
{
	return _overflow;
}

bool 	Scalar::isImpossible(void) const
{
	return _impossible;
}

void Scalar::print( void )
{
	if (_impossible)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;	
		return ;	
	}

	if (_value < 0.0 || _value > 255.0)
		std::cout << "char: overflow" << std::endl;
	else {
		if (std::isprint(_value))
			std::cout << "char: " << this->toChar() << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (_value < 0.0 || _value > 255.0)
		
	else
		std::cout << "int: " << this->toInt() << std::endl;

	std::cout << "float: " << this->toFloat() << std::endl;
	std::cout << "double: " << this->toDouble() << std::endl;
}


