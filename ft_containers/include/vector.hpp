#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

template <class T, class container = allocator<T> >
class vector
{
public:
	vector<T>() {

	}
	vector(vector &vector);
	virtual ~vector();
	vector &operator=(const vector &vector);

private:

};

#endif