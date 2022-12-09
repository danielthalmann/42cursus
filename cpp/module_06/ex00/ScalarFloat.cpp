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
	char const *literal[] = {"-inff", "+inff", "nanf"};
	
	for (size_t i = 0; i < 3; i++)
	{
		if (literal[i] == value)
			return true;
	}

	if (value[i] == '-' || value[i] == '+')
		i++;

	while (value[i])
	{
		if (i == (int)(value.length() - 1))
		{
			if (value[i] != 'f')
				return false;
		}
		else if (value[i] == '.')
		{
			if (comma)
				return false;
			comma = true;
		}
		else if (!std::isdigit(value[i]))
			return false;

		i++;
	}

	return true;
}

std::string ScalarFloat::getType(void) const
{
	return std::string("float");
}

void ScalarFloat::parse(const std::string &value)
{
	if(value == "-inff")
	{
		_value = -std::numeric_limits<float>::infinity();
		_infinity_m = true;
		return ;
	}

	if(value == "+inff")
	{
		_value = std::numeric_limits<float>::infinity();
		_infinity_p = true;
		return ;
	}

	if(value == "nanf")
	{
		_impossible = true;
		return ;
	}
	

	_value = std::atof(value.c_str());
}

std::ostream &operator<<(std::ostream &out, ScalarFloat const &value)
{
        out << "\x1b[33m" << value.toInt() << "\x1b[0m" << " " << std::endl;
        return out;
}

