#include "ScalarChar.hpp"

#define CLASSNAME "ScalarChar"

ScalarChar::ScalarChar() : Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarChar::ScalarChar(ScalarChar &obj) : Scalar(obj)
{
	(*this) = (obj);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarChar::~ScalarChar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarChar &ScalarChar::operator=(const ScalarChar &obj)
{
	_value = obj._value;
	_overflow = obj._overflow;
	_impossible = obj._impossible;

	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

Scalar 	*ScalarChar::clone(void)
{
	return new ScalarChar();
}

bool ScalarChar::canParsed(const std::string &value) const
{

	if (value.length() != 1)
		return false;

	if (std::isdigit(value[0]))
		return false;

	return true;
}

std::string ScalarChar::getType(void) const
{
	return std::string("char");
}

void ScalarChar::parse(const std::string &value)
{	
	_value = static_cast<char>(value[0]);
}

std::ostream &operator<<(std::ostream &out, ScalarChar const &value)
{
    out << "\x1b[33m" << value.toInt() << "\x1b[0m" << " " << std::endl;
    return out;
}
