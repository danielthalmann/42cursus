#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <class T, class allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T						value_type;
		typedef T*						pointer;
		typedef const T*				const_pointer;
		typedef T&						reference;
		typedef const T&				const_reference;
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
		typedef ptrdiff_t				difference_type;
		typedef allocator				allocator_type;

		/**
		 * @brief Construct a new vector object
		 * 
		 */
		vector () {

		}
		vector(size_type n, const_reference value, allocator_type a = allocator_type()) : _allocator(a), _size(n)
		{ 
			(void) value;
			allocate (n);
		}
		vector(vector &vector);
		virtual ~vector();
		vector &operator=(const vector &vector);

		iterator begin() 				{	return iterator(this->_start); }
		const_iterator begin() const	{	return const_iterator(this->_start); }
		iterator end()					{	return iterator(this->_end); }
		const_iterator end() const		{	return const_iterator(this->_end); }

		size_type size()				{ 	return size_type(this->_end - this->_start); }
		
		size_type max_size() const		{	return size_type(_allocator.max_size()); }
    	
		void resize(size_type n, value_type v = value_type()) {
			if (n > size())
				fill_insert(end(), n - size(), v);
			else if (n < size())
				erase_at_end(this->_start + n);
		}

		bool empty()							{	return begin() == end(); }

		reference operator[](size_type n)		{	return *(this->_start + n); }
		const_reference operator[](size_type n) const	{	return *(this->_start + n); }

    	reference at(size_type n) 				{	range_check(n); return (*this)[n]; }
    	const_reference at(size_type n) const	{	range_check(n); return (*this)[n]; }

		reference front()						{	return *begin(); }
		const_reference front()	const			{	return *begin(); }

		reference back()						{	return *(end() - 1); }
		const_reference back()	const			{	return *(end() - 1); }

		pointer data()							{	return this->_start; }
		const_pointer data()	const			{	return this->_start; }

	protected:

		void assign( size_type count, const T& value );
		void allocate(size_type n) { _start = _allocator.allocate(n); _end = _start + n; }
		void fill_insert(iterator end, size_type n, reference v) {	}
		void erase_at_end(pointer end) {	
			_allocator.deallocate(this->_end - end);
			this->_end = end;
		}

		void range_check(size_type n) const
		{
			if (n >= this->size())
				throw std::out_of_range();
		}


	private:
		pointer			_start;
		pointer			_end;
		size_type		_size;
		allocator_type	_allocator;


	};

}
#endif