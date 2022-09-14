#include "ScalarInt.hpp"

#define CLASSNAME "ScalarInt"

ScalarInt::ScalarInt() : Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarInt::ScalarInt(ScalarInt &obj) : Scalar(obj)
{
	(*this) = (obj);
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

ScalarInt &ScalarInt::operator=(const ScalarInt &obj)
{
	_value = obj._value;
	_overflow = obj._overflow;
	_impossible = obj._impossible;

	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

Scalar 	*ScalarInt::clone(void)
{
	return new ScalarInt();
}

bool ScalarInt::canParsed(const std::string &value) const
{
	int i = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;

	while (value[i])
	{
		if (!std::isdigit(value[i]))
			return false;
		i++;
	}

	return true;
}

std::string ScalarInt::getType(void) const
{
	return std::string("int");
}

std::ostream &operator<<(std::ostream &out, ScalarInt const &value)
{
        out << "\x1b[33m" << value.toInt() << "\x1b[0m" << " " << std::endl;
        return out;
}
