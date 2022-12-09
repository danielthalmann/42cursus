
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

void normalTest(std::vector<int> &v)
{
	std::cout << std::endl;

	try {

		std::cout << "test :" << std::endl;
		Span span(v.size());
		span.addNumber(v.begin(), v.end());

		displayContentSpan(span);
		displayLong(span);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
}

void limitTest(std::vector<int> &v)
{
	std::cout << std::endl;

	try {

		std::cout << "test limit :" << std::endl;
		Span span(2);
		span.addNumber(v.begin(), v.end());

		displayContentSpan(span);
		displayLong(span);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
}

void sizeTest()
{
	std::cout << std::endl;

	try {
		std::cout << "test size :" << std::endl;
		Span span(2);
		span.addNumber(99);

		displayContentSpan(span);
		displayLong(span);
	
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
}



int main ( void )
{
	std::vector<int> v;
	
	v.push_back(2);
	v.push_back(24);
	v.push_back(42);

	limitTest(v);
	sizeTest();
	normalTest(v);

	v.push_back(-26);
	v.push_back(-24);
	normalTest(v);

	std::cout << std::endl;
	
	return (0);
}
