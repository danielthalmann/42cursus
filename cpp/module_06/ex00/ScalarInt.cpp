#include "ScalarInt.hpp"

#define CLASSNAME "ScalarInt"

ScalarInt::ScalarInt()
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
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

Scalar 	*ScalarInt::clone(void)
{
	return new ScalarInt();
}

void ScalarInt::parse(const std::string &value)
{
	_value = atoi(value.c_str());
}

bool ScalarInt::canParsed(const std::string &value) const
{
	int i = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;

	while (value[i])
	{
		if (!isdigit(value[i]))
			return false;
		i++;
	}

	return true;
}

std::string ScalarInt::getType(void) const
{
	return std::string("int");
}

char 	ScalarInt::toChar(void) const
{
	return static_cast<char>(_value);
}

int 	ScalarInt::toInt(void) const
{
	return static_cast<int>(_value);
}

float 	ScalarInt::toFloat(void) const
{
	return static_cast<float>(_value);
}

double 	ScalarInt::toDouble(void) const
{
	return static_cast<double>(_value);
}

std::ostream &operator<<(std::ostream &out, ScalarInt const &value)
{
        out << "\x1b[33m" << value.toInt() << "\x1b[0m" << " " << std::endl;
        return out;
}