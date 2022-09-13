
#include "Convert.hpp"
#include <iostream>

int main ( int argc, char **argv )
{

	if (argc < 2)
	{
		std::cerr << "error : not enought parameter" << std::endl; 
		return (0);
	}

	try
	{
		Convert c;
		std::string value(argv[1]);

		Scalar *s = c.scalar(value);
		s->parse(value);

		std::cout << s->getType() << std::endl;

		std::cout << "char:" << s->toChar() << std::endl;
		std::cout << "int:" << s->toInt() << std::endl;
		std::cout << "float:" << s->toFloat() << std::endl;
		std::cout << "double:" << s->toDouble() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
