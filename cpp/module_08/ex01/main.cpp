
#include <iostream>
#include "Span.hpp"


void displayLong(Span &span)
{
	std::cout << "longest span : " << span.longestSpan() << std::endl;
	std::cout << "shortest span : " << span.shortestSpan() << std::endl;
}

void displayContentSpan(Span &span)
{
	std::cout << "values : ";
	for (Span::iterator iter = span.begin(); 
		iter != span.end(); 
		++iter )
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

int main ( void )
{

	try {

		std::vector<int> v;
		
		v.push_back(2);
		v.push_back(24);
		v.push_back(42);

		Span spanA(2);

		spanA.addNumber(v.begin(), v.end());

		displayContentSpan(spanA);
		displayLong(spanA);

		Span spanB(3);

		spanB.addNumber(1);
		spanB.addNumber(13);
		spanB.addNumber(5);

		displayContentSpan(spanB);
		displayLong(spanB);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
