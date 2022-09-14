
#include "Convert.hpp"
#include <iostream>

int main ( int argc, char **argv )
{
/*
	double max = std::numeric_limits<double>::max();
	double min = std::numeric_limits<double>::min();
    double inf = std::numeric_limits<double>::infinity();
 
    if(inf > max)
        std::cout << inf << " is greater than " << max << '\n';
    if(-inf < min)
        std::cout << -inf << " is small than " << min << '\n';
*/

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

		//std::cout << s->getType() << std::endl;
		s->print();

		delete s;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
