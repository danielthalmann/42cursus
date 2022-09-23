
#include <iostream>
#include "Span.hpp"

int main ( void )
{

	try {

		Span span(3);

		span.addNumber(1);
	//	span.addNumber(13);
	//	span.addNumber(5);

		std::cout << "longestSpan : " << span.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
