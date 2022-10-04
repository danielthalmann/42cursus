#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

template <class T, class alloc = std::allocator<T> >
class vector
{
public:
      typedef T						value_type;
      typedef T*						pointer;
      typedef const T*					const_pointer;
      typedef T&						reference;
      typedef const T&					const_reference;
      typedef std::iterator<std::input_iterator_tag, 
            value_type, 
            value_type, 
            pointer, 
            reference> iterator;
      typedef     const std::iterator<std::input_iterator_tag, 
            value_type, 
            value_type, 
            pointer, 
            reference> const_iterator;
      typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
      typedef std::reverse_iterator<iterator>		reverse_iterator;
      typedef size_t					size_type;
      typedef ptrdiff_t					difference_type;
      typedef _Alloc					allocator_type;

	vector<T>() {

	}
	vector(vector &vector);
	virtual ~vector();
	vector &operator=(const vector &vector);

private:

};

#endif