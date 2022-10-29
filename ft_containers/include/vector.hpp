#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "algorithm.hpp"
#include "type_traits.hpp"

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
		private:
			T* _cursor;
		public:
			iter() : _cursor(0) {}
			iter(T* start) : _cursor(start) {}
			iter& operator++() { _cursor++; return *this; }
			iter operator++(int) {iter retval = *this; ++(*this); return retval; }
			iter& operator--() { _cursor--; return *this; }
			iter operator--(int) {iter retval = *this; --(*this); return retval; }
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
			this->_finish = this->_start;
			while (this->_finish != this->_end) {
				_allocator.construct(this->_finish, v);
				this->_finish++;
			}
		}

		vector(vector &vector) :  _start(0), _end(0), _finish(0) {	
			*this = vector;
		}
		
		virtual ~vector() {
			erase_at_end(this->_start);
		}
		
		vector &operator=(const vector &vector) {
			assign( vector.begin(), vector.end() );
			return *this;
		}

		void assign(size_type n, const_reference v) {
			destruct(_start, _finish);
			if (n > capacity())
				grow(n);
			_finish = _start + n;
			while ( n-- ) {
				_allocator.construct((_start + n), v);
			}
		}

		template < class InputIterator >
		void assign( InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0) {
			const size_type n = std::distance(first, last);
			destruct(_start, _finish);
			if (n > capacity())
				grow(n);
			_finish = _start;
			while (first != last) {
				_allocator.construct(_finish, (*first));
				++first;
				++_finish;

			}
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
		iterator end()							{	return iterator(this->_finish); }
		const_iterator end() const				{	return const_iterator(this->_finish); }
    
		reverse_iterator       rbegin()			{	return reverse_iterator(end()); }
		const_reverse_iterator rbegin()  const	{	return const_reverse_iterator(end()); }
		reverse_iterator       rend()			{	return reverse_iterator(begin()); }
		const_reverse_iterator rend() const 	{	return const_reverse_iterator(begin()); }

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
			if (size() + 1 > capacity())
				grow(1);
			iterator e = end();
			if ( e == pos ) {
				*e = value;
				return pos;
			}
			else {
				while ( e-- != pos ){
					*(e + 1) = *e;
				}
				*pos = value;
			}
			_finish++;
			return pos;
		}

		iterator erase (iterator pos) {
			if (pos == end())
				return pos;

			size_type i = size() - std::distance(pos, end());

			while (i < size() - 1) {
				this->_start[i] = this->_start[i + 1];
				i++;
			}
			pop_back();
			return pos;
		}

		iterator erase (iterator first, iterator last ) {
			const size_type n = std::distance(first, last);
			_finish -= n;
			destruct( &(*(first)), &(*(last)) );
			while (last != end()) {
				*first = *last;
				last++;
			}
			return first;
		}

	    void push_back(const value_type& v) {
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
				this->_allocator.destroy(this->_finish);
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

		void grow(size_type n) {
			if(!this->_start) {
				init_allocate(n);
				return;
			}
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
			if (start)
			{
				while (start != end)
				{
					_allocator.destroy(start);
					start++;
				}	
			}
		}

		void erase_at_end(pointer end) {
			if(end < _finish)
				destruct(end, _finish);
			_allocator.deallocate(end, this->_end - end);
			this->_end = end;
		}

		void range_check(size_type n) const {
			if (n >= size())
				throw std::out_of_range("out of range");
		}


	protected:

		/**
		 *	_start     _finish       _end
		 *	   │           │           │
		 *	  ┌▼┌─┬─┬─┬─┬─┐▼──────────┐▼
		 *	  │ │ │ │ │ │ │           │
		 *	  └─┴─┴─┴─┴─┴─┴───────────┘
		 * 
		 */	
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
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template< class T, class allocator >
	bool operator!=(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		return !(lhs == rhs);
	}

	template< class T, class allocator >
	bool operator<(const vector< T, allocator > &lhs, const vector< T, allocator > &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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