#include "ScalarInt.hpp"

#define CLASSNAME "ScalarInt"

ScalarInt::ScalarInt()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarInt::ScalarInt(double value)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct set value" << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	_value = value;
}

ScalarInt::ScalarInt(ScalarInt &scalarint)
{
	(*this) = (scalarint);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarInt::~ScalarInt()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarInt &ScalarInt::operator=(const ScalarInt &scalarint)
{
	_value = scalarint._value;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

void ScalarInt::parse(const std::string &value)
{
	 (void) value;
}

bool ScalarInt::canParsed(const std::string &value) const
{
	if (value == "")
		return false;

	return false;
}

std::string ScalarInt::getType() const
{
	return std::string("int");
}