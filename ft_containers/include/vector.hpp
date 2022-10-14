#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>

#define DEBUG_INFO(T) (std::cout << T << std::endl);

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
		
		class iter: public std::iterator<
                        std::input_iterator_tag,     // iterator_category
                        value_type,                           // value_type
                        value_type,                           // difference_type
                        const_pointer,                    // pointer
                        reference                            // reference
                    > {
			T* _cursor;
		public:
			iter() : _cursor(0) {}
			iter(T* start) : _cursor(start) {}
			iter& operator++() { _cursor++; return *this; }
			iter operator++(int) {iter retval = *this; ++(*this); return retval; }
			iter& operator=(iter other) const { _cursor = other._cursor; return *this; }
			iter operator-(int value) const { return iter(_cursor - value); }
			iter operator+(int value) const { return iter(_cursor + value); }
			bool operator==(iter other) const {return _cursor == other._cursor;}
			bool operator!=(iter other) const {return !(*this == other);}
			reference operator*() const {return *_cursor;}
		};

		typedef iter					iterator;
		
		typedef const iter				const_iterator;
		
		typedef std::reverse_iterator<iterator>		reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef size_t					size_type;
		typedef ptrdiff_t				difference_type;
		typedef allocator				allocator_type;

		/**
		 * @brief Construct a new vector object
		 * 
		 */
		vector () : _start(0), _end(0), _finish(0)
		{ 

		}
		vector(size_type n, const_reference v, allocator_type a = allocator_type()) :  _start(0), _end(0), _finish(0), _allocator(a)
		{ 
			init_allocate(n);
			pointer start = this->_start + n;
			while (start != this->_end) {
				_allocator.construct(start, v);
			}
		}

		vector(vector &vector) {	
			*this = vector;
		}
		
		virtual ~vector() {
			destruct(this->_start, this->_finish);
			erase_at_end(this->_start);
		}
		
		vector &operator=(const vector &vector) {
			// TODO
		}

		void assign(size_type n, const_reference v) {
			// TODO
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last ) {
			// TODO
		}

		allocator_type get_allocator() const	{	return this->_allocator; };


		/**
		 * Element access 
		 */

    	reference at(size_type n) 				{	range_check(n); return (*this)[n]; }
    	const_reference at(size_type n) const	{	range_check(n); return (*this)[n]; }
		reference operator[](size_type n)		{	return *(this->_start + n); }
		const_reference operator[](size_type n) const	{	return *(this->_start + n); }
		reference front()						{	return *begin(); }
		const_reference front()	const			{	return *begin(); }
		reference back()						{	return *(end() - 1); }
		const_reference back()	const			{	return *(end() - 1); }
		pointer data()							{	return this->_start; }
		const_pointer data()	const			{	return this->_start; }


		/**
		 * Iterators
		 */

		iterator begin() 						{	return iterator(this->_start); }
		const_iterator begin() const			{	return const_iterator(this->_start); }
		iterator end()							{	return iterator(this->_end); }
		const_iterator end() const				{	return const_iterator(this->_end); }
    
		reverse_iterator       rbegin()			{	return reverse_iterator(this->_end); }
		const_reverse_iterator rbegin()  const	{	return const_reverse_iterator(this->_end); }
		reverse_iterator       rend()			{	return reverse_iterator(this->_start); }
		const_reverse_iterator rend() const 	{	return const_reverse_iterator(this->_start); }

		/**
		 * Capacity
		 */

		bool empty()							{	return begin() == end(); }
		size_type size() const					{ 	return size_type(this->_finish - this->_start); }
		size_type max_size() const				{	return size_type(_allocator.max_size()); }
		void reserve( size_type n )		{	
		    if (n > capacity())
				grow(n);
		}
		size_type capacity() const				{	return size_type(this->_end - this->_start); }


		/**
		 *  Modifiers 
		 */
		void clear()							{	destruct(this->_start, this->_finish); this->_finish = this->_start; }

		iterator insert( const_iterator pos, const T& value ) {
			// TODO
		}

		iterator erase (iterator position){
			// TODO
		}
		iterator erase (iterator first, iterator last){
			// TODO
		}

	    void push_back(const value_type& v) {
			// std::cout << "push_back " << capacity() << std::endl;
			if (this->_finish == this->_end) {
				grow((capacity() * 2) + 1);
			}
			*this->_finish = v;
			this->_finish++;
		}

		void pop_back() {
			
			if (size() > 0)
			{
				this->_finish--;
				_allocator.destroy(this->_finish);
			}

		}

		void resize(size_type n, value_type v = value_type()) {
			if (n > size())
				fill_insert(n, v);
			else if (n < size())
				erase_at_end(this->_start + n);
		}



		void swap( vector<T, allocator>& other ) {

			std::swap(this->_start, other._start);
			std::swap(this->_end, other._end);
			std::swap(this->_finish, other._finish);

		}


	protected:

		void realloc_insert(const value_type& v) {
			reserve(capacity() + 1);
		}

		void grow(size_type n) {
			pointer oldstart = this->_start;
			pointer oldend = this->_end;
			size_type s = size();
			this->_start = _allocator.allocate(n, this->_start);
			for (size_type i = 0; i < s; ++i){
				_allocator.construct(this->_start + i, *(oldstart + i));
				_allocator.destroy(oldstart + i);
			}
			this->_end = this->_start + n;
			this->_finish = this->_start + s;
			if (oldend - oldstart > 0)
				_allocator.deallocate(oldstart, oldend - oldstart);
		}

		void init_allocate(size_type n) { 
			_start = _allocator.allocate(n); 
			this->_finish = this->_start; 
			_end = this->_start + n;
		}
		
		void fill_insert(size_type n, reference v) {
			if (n > capacity()) {
				if (this->_start)
					grow(n);
				else
					init_allocate(n);
			}
			pointer start = this->_finish;
			while (start != this->_end) {
				_allocator.construct(start, v);
				start++;
			}
		}

		void destruct(pointer start, pointer end) {
			while (start != end)
			{
				_allocator.destroy(start);
				start++;
			}	
		}

		void erase_at_end(pointer end) {	
			_allocator.deallocate(end, this->_end - end);
			this->_end = end;
		}

		void range_check(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("out of range");
		}


	protected:

	
		pointer			_start;
		pointer			_end;
		pointer			_finish;
		allocator_type	_allocator;

	};

	/* Relationnal operators */
	template< class T, class allocator >
	bool operator==(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		if (lhs.size() != rhs.size()) 
			return (false);
		// TODO
		return false;
	}

	template< class T, class allocator >
	bool operator!=(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		return !(lhs == rhs);
	}

	template< class T, class allocator >
	bool operator<(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		// TODO
		return false;
	}

	template< class T, class allocator >
	bool operator<=(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		return !(rhs < lhs);
	}

	template< class T, class allocator >
	bool operator>(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		return rhs < lhs;
	}

	template< class T, class allocator >
	bool operator>=(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		return !(lhs < rhs);
	}

	template< class T, class allocator >
	void swap( vector<T,allocator>& lhs, vector<T,allocator>& rhs )
	{
		lhs.swap(rhs);
	}

}


#endif