#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"
#include "tree.hpp"

#define DEBUG_INFO(T) (std::cout << T << std::endl);

namespace ft
{
	template <	class Key, 
				class Val,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key, Val> > >
	class map
	{
	public:
		typedef Key 						key_type;
		typedef Val							mapped_type;
		typedef ft::pair<const Key, Val>	value_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Compare						key_compare;
		typedef Allocator					allocator_type;

		typedef value_type&					reference;
		typedef const value_type&			const_reference;

		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		typedef Tree<value_type, allocator_type> tree_type;

		typedef typename tree_type::iterator 		iterator;
		typedef typename tree_type::const_iterator	const_iterator;

		typedef typename tree_type::reverse_iterator 		reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map<Key, Val, Compare, Allocator>;
      	protected:
			Compare comp;

			value_compare(Compare c) : comp(c) { }
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const
			{ return comp(x.first, y.first); }
      	
		};


		/**
		 * @brief Construct a new vector object
		 * 
		 */
		map() : _tree(), _comp(), _allocator(){  /* TODO */}

		map(const Compare& comp, const Allocator& alloc = allocator_type()) : _tree(), _comp(comp), _allocator(alloc) { /* TODO */ }

		template< typename InputIterator >
		map(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0)
			   : _tree(), _comp(), _allocator(alloc)
		{
			_tree.assign(first, last);
		}

		map(map &other) {	*this = other;	}
		
		virtual ~map() { }
		
		map& operator=(const map &m) 
		{
			_comp = m._comp;
			_tree.assign( m.begin(), m.end() );
			return *this;
		}

		allocator_type get_allocator() const	{	return this->_allocator; };

		/**
		 * Element access 
		 */

		Val& at(size_type n) 					{	range_check(n); iterator i = begin(); while (n)	{ i++; n--; } return *i; }
		const Val& at(size_type n) const		{	range_check(n); iterator i = begin(); while (n)	{ i++; n--; } return *i; }

		/* TODO
		Val& operator[]( const Key& key)		{	

			value_type obj = value_type(key, mapped_type());
			return (*(_tree.insert(_comp, obj).first)).second;

		}
		*/

		/**
		 * Iterators
		 */

		iterator begin() 						{	_tree.begin(); }
		const_iterator begin() const			{	_tree.begin(); }
		iterator end()							{	_tree.end(); }
		const_iterator end() const				{	_tree.end(); }
    
		reverse_iterator       rbegin()			{	_tree.rbegin(); }
		const_reverse_iterator rbegin()  const	{	_tree.rbegin(); }
		reverse_iterator       rend()			{	_tree.rend();  }
		const_reverse_iterator rend() const 	{	_tree.rend();  }

		/**
		 * Capacity
		 */

		bool empty() const						{	return (_tree.size() == 0); }
		size_type size() const					{	return _tree.size(); }
		size_type max_size() const				{	return size_type(_allocator.max_size()); }
				
		/**
		 *  Modifiers 
		 */

		void clear()							{	_tree.clear(); }

		ft::pair<iterator, bool> insert( const value_type& value  ) { _tree.insert(value); }

		/* TODO 
		iterator erase (iterator pos) { _tree.search(*pos); }
	
		iterator erase (iterator first, iterator last ) { // TODO  }

		size_type erase( const Key& key ) { // TODO  }
		*/
		 
		void swap( map<Key, Val, Allocator>& other ) 
		{
			tree_type temp;

			temp.assign(begin(), end());
			_tree.assign(other.begin(), other.end());
			other._tree.assign(temp.begin(), temp.end());

		}
				
		/**
		 *  Lookup 
		 */
		size_type count( const Key& key ) const {/* TODO */ }

		iterator find( const Key& key ) {/* TODO */ }
		const_iterator find( const Key& key ) const {/* TODO */ }

		ft::pair<iterator,iterator> equal_range( const Key& key ) {/* TODO */ }
		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {/* TODO */ }

		iterator lower_bound( const Key& key ) {/* TODO */ }
		const_iterator lower_bound( const Key& key ) const {/* TODO */ }

		iterator upper_bound( const Key& key ) {/* TODO */ }
		const_iterator upper_bound( const Key& key ) const {/* TODO */ }

		/**
		 *  Observers 
		 */	
		key_compare key_comp() const {/* TODO */ }
		value_compare value_comp() const { return value_compare(key_comp()); }
	

	protected:

		tree_type		_tree;
		Compare 		_comp;
		Allocator 		_allocator;


		void range_check(size_type n) const {
			if (n >= size())
				throw std::out_of_range("out of range");
		}

	};

	/* Relationnal operators */
	template< class Key, class T, class Compare, class Alloc >
	bool operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()) 
			return (false);
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

}


#endif