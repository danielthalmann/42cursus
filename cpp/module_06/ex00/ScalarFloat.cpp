#include "ScalarFloat.hpp"

#define CLASSNAME "ScalarFloat"

ScalarFloat::ScalarFloat() : Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarFloat::ScalarFloat(ScalarFloat &obj) : Scalar(obj)
{
	(*this) = (obj);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarFloat::~ScalarFloat()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarFloat &ScalarFloat::operator=(const ScalarFloat &obj)
{
	_value = obj._value;
	_overflow = obj._overflow;
	_impossible = obj._impossible;

	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

Scalar 	*ScalarFloat::clone(void)
{
	return new ScalarFloat();
}

bool ScalarFloat::canParsed(const std::string &value) const
{
	int i = 0;
	bool comma = false;

	if (value[i] == '-' || value[i] == '+')
		i++;

	while (value[i])
	{
		if (!std::isdigit(value[i]) && (comma && value[i] == '.'))
			return false;
		i++;
	}

	return true;
}

std::string ScalarFloat::getType(void) const
{
	return std::string("float");
}

std::ostream &operator<<(std::ostream &out, ScalarFloat const &value)
{
        out << "\x1b[33m" << value.toInt() << "\x1b[0m" << " " << std::endl;
        return out;
}
