#include "ScalarDouble.hpp"

#define CLASSNAME "ScalarDouble"

ScalarDouble::ScalarDouble() : Scalar()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarDouble::ScalarDouble(ScalarDouble &obj) : Scalar(obj)
{
	(*this) = (obj);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarDouble::~ScalarDouble()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ScalarDouble &ScalarDouble::operator=(const ScalarDouble &obj)
{
	_value = obj._value;
	_overflow = obj._overflow;
	_impossible = obj._impossible;

	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

Scalar 	*ScalarDouble::clone(void)
{
	return new ScalarDouble();
}

bool ScalarDouble::canParsed(const std::string &value) const
{
	int i = 0;
	bool comma = false;
	char const *literal[] = {"-inf", "+inf", "nan"};
	
	for (size_t i = 0; i < 3; i++)
	{
		if (literal[i] == value)
			return true;
	}

	if (value[i] == '-' || value[i] == '+')
		i++;

	while (value[i])
	{
		if (value[i] == '.')
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

std::string ScalarDouble::getType(void) const
{
	return std::string("double");
}

void ScalarDouble::parse(const std::string &value)
{
	if(value == "-inf")
	{
		_value = -std::numeric_limits<double>::infinity();
		_infinity_m = true;
		return ;
	}

	if(value == "+inf")
	{
		_value = std::numeric_limits<double>::infinity();
		_infinity_p = true;
		return ;
	}

	if(value == "nan")
	{
		_impossible = true;
		return ;
	}
	
	_value = std::atof(value.c_str());
}

std::ostream &operator<<(std::ostream &out, ScalarDouble const &value)
{
        out << "\x1b[33m" << value.toInt() << "\x1b[0m" << " " << std::endl;
        return out;
}

