#include "Convert.hpp"

#define CLASSNAME "Convert"

Convert::Convert()
{
	_scalar[0] = new ScalarChar();
	_scalar[1] = new ScalarInt();
	_scalar[2] = new ScalarFloat();
	_scalar[3] = new ScalarDouble();
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Convert::Convert(Convert &convert)
{
	(*this) = (convert);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Convert::~Convert()
{
	for (int i = 0; i < Convert::scalar_length; i++)
	{
		delete _scalar[i];
	}

	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Convert &Convert::operator=(const Convert &convert)
{
	(void)convert;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

Scalar *Convert::scalar(std::string s)
{

	for (int i = 0; i < Convert::scalar_length; i++)
	{
		if (_scalar[i]->canParsed(s))
			return _scalar[i]->clone();
	}
	
	throw ConversionNotPossibleException();

	return NULL;
}
