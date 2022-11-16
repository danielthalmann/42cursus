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

		typedef typename ft::Tree<value_type, allocator_type>::iterator 		iterator;
		typedef ft::random_access_iterator< const_pointer >	const_iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map<Key, Val, Compare, Allocator>;
      	protected:
			Compare comp;

			value_compare(Compare c) : comp(c) { }
		public:
			bool operator() (const value_type& x, const value_type& y) const
			{ return comp(x.first, y.first); }
      	
		};


		/**
		 * @brief Construct a new vector object
		 * 
		 */
		map() : _tree(), _comp(), _allocator(){  /* TODO */}

		map(const Compare& comp, const Allocator& alloc = allocator_type())  { /* TODO */ }

		template< typename InputIterator >
		map(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0)
		{	/* TODO */	}

		map(map &other) {	/* TODO */	}
		
		virtual ~map() { /* TODO */	}
		
		map& operator=(const map &vector) { /* TODO */ }

		template < class InputIterator >
		void assign( InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0) {

			while (first != last)
			{
				first++;
			}
			

		}

		allocator_type get_allocator() const	{	return this->_allocator; };

		/**
		 * Element access 
		 */

		Val& at(size_type n) 					{	/* TODO */ }
		const Val& at(size_type n) const		{	/* TODO */ }
		Val& operator[]( const Key& key)		{	/* TODO */  }

		/**
		 * Iterators
		 */

		iterator begin() 						{	/* TODO */ }
		const_iterator begin() const			{	/* TODO */ }
		iterator end()							{	/* TODO */ }
		const_iterator end() const				{	/* TODO */ }
    
		reverse_iterator       rbegin()			{	/* TODO */ }
		const_reverse_iterator rbegin()  const	{	/* TODO */ }
		reverse_iterator       rend()			{	/* TODO */ }
		const_reverse_iterator rend() const 	{	/* TODO */ }

		/**
		 * Capacity
		 */

		bool empty() const						{	return (_tree.size() == 0); }
		size_type size() const					{	return _tree.size(); }
		size_type max_size() const				{	return size_type(_allocator.max_size()); }
				
		/**
		 *  Modifiers 
		 */

		void clear()							{	/* TODO */ }

		ft::pair<iterator, bool> insert( const value_type& value  ) {	/* TODO */ }

		iterator erase (iterator pos) { /* TODO */ }
		
		iterator erase (iterator first, iterator last ) {/* TODO */ }

		size_type erase( const Key& key ) {/* TODO */ }

		void swap( map<Key, Val, Allocator>& other ) {/* TODO */ }
				
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