#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"

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
	
		
		typedef ft::random_access_iterator< pointer > iterator;
		typedef ft::random_access_iterator< const_pointer >	const_iterator;

		typedef ft::reverse_iterator<iterator>		reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef size_t					size_type;
		typedef ptrdiff_t				difference_type;
		typedef allocator				allocator_type;

		/**
		 * @brief Construct a new vector object
		 * 
		 */
		explicit vector (const allocator_type &a = allocator_type()) : _start(0), _end(0), _finish(0), _allocator(a)
		{ 

		}

		explicit vector(size_type n, const_reference v = value_type(), const allocator_type &a = allocator_type()) :  _start(0), _end(0), _finish(0), _allocator(a)
		{ 
			init_allocate(n);
			this->_finish = this->_start;
			while (this->_finish != this->_end) {
				_allocator.construct(this->_finish, v);
				this->_finish++;
			}
		}

		template< typename InputIterator >
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0)
			: _start(0), _end(0), _finish(0), _allocator(alloc)
		{
			assign( first, last );
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
			const size_type n = ft::distance(first, last);

			if (size()) {
				destruct(this->_start, this->_finish);
				_finish = _start;			
			}
			if (n > capacity())
				grow(n);
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

		bool empty() const						{	return _start == _finish; }
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

		iterator insert( iterator pos, const T& value ) {

			size_type i = ft::distance(begin(), pos);

			if (size() + 1 > capacity())
				grow((capacity() ? capacity() * 2 : 1));

			pointer elem = this->_start + i;

			if ( elem == this->_finish ) {
				*(this->_finish) = value;
			}
			else {
				pointer cur = this->_finish;
				while ( cur > elem ) {
					*cur = *(cur - 1);
					cur--;
				}
				*elem = value;
			}
			this->_finish++;
			return iterator( elem );
		}

		iterator erase (iterator pos) {
			if (pos == end())
				return pos;

			size_type i = size() - ft::distance(pos, end());

			while (i < size() - 1) {
				this->_start[i] = this->_start[i + 1];
				i++;
			}
			pop_back();
			return pos;
		}

		iterator erase (iterator first, iterator last ) {
			
			const size_type n = ft::distance(first, last);

			destruct( &(*(first)), &(*(last)) );
		
			iterator f = first;
			while (last < end()) {
				*f = *last;
				last++;
				f++;
			}
			this->_finish -= n;

			return first;
		}

	    void push_back(const value_type& v) {
			if (this->_finish == this->_end) {
				grow((capacity() ? capacity() * 2 : 1));
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
			else if (n < size()) {
				destruct(this->_start + n, this->_finish);
				this->_finish = this->_start + n;
			}
		}

		void swap( vector<T, allocator>& other ) {
			ft::swap(this->_start, other._start);
			ft::swap(this->_end, other._end);
			ft::swap(this->_finish, other._finish);
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
			while (this->_finish != this->_end) {
				_allocator.construct(this->_finish, v);
				this->_finish++;
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
		 *  _start  : pointer of start of array
		 *  _end    : pointer of end of array. he is 1 position after the last element capacity
		 *  _finish : pointer of end of filled element. he is 1 position after the last element size
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