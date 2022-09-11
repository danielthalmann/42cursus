#include "Scalar.hpp"
#include "ScalarInt.hpp"

#define CLASSNAME "Scalar"


ScalarInt Scalar::toInt() const
{
	ScalarInt s(_value);
	return s;
}

void Scalar::convert(std::string s)
{
	std::cout << s << std::endl;
}