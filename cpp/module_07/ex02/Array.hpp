#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
	Array( void );
	Array(size_t size);
	Array(Array<T> &array);
	virtual ~Array();
	Array<T> &operator=(const Array<T> &array);
	T &operator[](size_t i);

	int size();

	class OutOfLimitException : public std::exception
	{
		virtual const char * what(void) const throw()
		{
			return "Array index out of limit";	
		}
	};

private:
	T 		*_values;
	size_t	_size;

};

#include "Array.tpp"

#endif