#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

template <class T, class alloc = std::allocator<T> >
class vector
{
public:
      typedef T							value_type;
      typedef T*						pointer;
      typedef const T*					const_pointer;
      typedef T&						reference;
      typedef const T&					const_reference;
      typedef std::iterator<std::input_iterator_tag, 
            value_type, 
            value_type, 
            pointer, 
            reference> iterator;
      typedef std::iterator<std::input_iterator_tag, 
            value_type, 
            value_type, 
            const_pointer, 
            reference> const_iterator;
      typedef std::reverse_iterator<iterator>		reverse_iterator;
      typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
      typedef size_t					size_type;
      typedef ptrdiff_t					difference_type;
      typedef alloc					allocator_type;

	/**
	 * @brief Construct a new vector object
	 * 
	 */
	vector () {

	}


	vector(size_type n, const_reference value, alloc a)
    { 
		_M_fill_initialize(__n, __value); 
	}

	vector(vector &vector);
	virtual ~vector();
	vector &operator=(const vector &vector);

	iterator begin()
	{
		return iterator(this->_start); 
	}
	const_iterator begin() const
	{ 
		return const_iterator(this->_start); 
	}

	iterator end()
	{
		return iterator(this->_end); 
	}
	const_iterator end() const
	{ 
		return const_iterator(this->_end); 
	}
protected:

	void allocate(size_type n)
	{
		__alloc_traits<alloc>::allocate(n)
	}


private:
	pointer	_start;
	pointer	_end;

};

#endif