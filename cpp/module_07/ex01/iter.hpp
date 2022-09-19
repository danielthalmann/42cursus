#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter (T *array, unsigned int size, void (*callback)(T &value))
{
	unsigned int i = 0;
	while (i++ < size)
		callback(array[i - 1]);
};

#endif