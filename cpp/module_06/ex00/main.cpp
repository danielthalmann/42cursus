
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

		delete s;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
