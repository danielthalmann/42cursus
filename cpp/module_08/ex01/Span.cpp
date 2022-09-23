#include "Span.hpp"

#define CLASSNAME "Span"

Span::Span()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_size_limit = 0;
}

Span::Span(unsigned int size)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct with size " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_size_limit = size;
}


Span::Span(Span &span)
{
	(*this) = (span);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Span::~Span()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Span &Span::operator=(const Span &span)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	_array.clear();
	_size_limit = span._size_limit;

	for (std::vector<unsigned int>::const_iterator iter = span._array.begin(); 
		iter != span._array.end(); 
		++iter )
	{
		_array.push_back(*iter);
	}

	return (*this);
}

void Span::addNumber (unsigned int n)
{
	if (_array.size() < _size_limit)
		_array.push_back(n);
	else
		throw std::range_error("Limit exceeded");
	
}

unsigned int Span::shortestSpan( void )
{
	if (_array.size() < 2)	
		throw std::domain_error("Size of list is not enought");

	for (std::vector<unsigned int>::const_iterator iter = _array.begin(); 
		iter != _array.end(); 
		++iter )
	{
		if (min > *iter)
			min = *iter;

		if (max < *iter)
			max = *iter;
	}


	return 0;
}

unsigned int Span::longestSpan( void )
{
	unsigned int min = std::numeric_limits<unsigned int>::max();
	unsigned int max = std::numeric_limits<unsigned int>::min();

	if (_array.size() < 2)	
		throw std::domain_error("Size of list is not enought");

	for (std::vector<unsigned int>::const_iterator iter = _array.begin(); 
		iter != _array.end(); 
		++iter )
	{
		if (min > *iter)
			min = *iter;

		if (max < *iter)
			max = *iter;
	}

	return (max - min);
}