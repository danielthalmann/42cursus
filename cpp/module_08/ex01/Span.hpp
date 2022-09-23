#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

class Span
{
public:
	Span();
	Span(unsigned int size);
	Span(Span &span);
	virtual ~Span();
	Span &operator=(const Span &span);

	void addNumber (unsigned int n);
	unsigned int shortestSpan( void );
	unsigned int longestSpan( void );


private:

	std::vector<unsigned int> _array;
	unsigned int _size_limit;

};

#endif