
#include "Scalar.hpp"
#include <iostream>

int main ( int argc, char **argv )
{

	if (argc < 2)
	{
		std::cout << "error : not enought parameter" << std::endl; 
		return (0);
	}

	Scalar::convert(std::string(argv[1]));

	return (0);
}
