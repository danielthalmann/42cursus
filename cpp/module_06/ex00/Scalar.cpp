#include "Scalar.hpp"

#define CLASSNAME "Scalar"

Scalar::Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_impossible = false;
	_overflow = false;
	_infinity_p = false;
	_infinity_m = false;
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

char 	Scalar::toChar(void) const
{
	return static_cast<char>(_value);
}

int 	Scalar::toInt(void) const
{
	return static_cast<int>(_value);
}

float 	Scalar::toFloat(void) const
{
	return static_cast<float>(_value);
}

double 	Scalar::toDouble(void) const
{
	return static_cast<double>(_value);
}

void Scalar::parse(const std::string &value)
{	
	_value = std::atof(value.c_str());
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

	if (_value < std::numeric_limits<char>::min() || _value > std::numeric_limits<char>::max())
		std::cout << "char: overflow" << std::endl;
	else {
		if (std::isprint(_value))
			std::cout << "char: '" << this->toChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	if (_value < std::numeric_limits<int>::min() || _value > std::numeric_limits<int>::max())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << this->toInt() << std::endl;
	
	if (_infinity_m)
	{
		std::cout << "float: -inff" << std::endl;
	}
	else if (_infinity_p)
	{
		std::cout << "float: +inff" << std::endl;
	}
	else
	{
		if (_value < std::numeric_limits<float>::min() || _value > std::numeric_limits<float>::max())
			std::cout << "float: overflow" << std::endl;
		else
		{
			if ( floor(_value) != _value )
				std::cout << "float: " << this->toFloat() << "f" << std::endl;
			else
				std::cout << "float: " << this->toFloat() << ".0f" << std::endl;
		}		
	}


	if (_infinity_m)
	{
		std::cout << "float: -inf" << std::endl;
	}
	else if (_infinity_p)
	{
		std::cout << "float: +inf" << std::endl;
	}
	else
	{
		if ( floor(_value) != _value )
			std::cout << "double: " << this->toDouble() << "" << std::endl;
		else
			std::cout << "double: " << this->toDouble() << ".0" << std::endl;
	}

}


