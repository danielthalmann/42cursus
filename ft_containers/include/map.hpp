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

		typedef Key 								key_type;
		typedef Val									mapped_type;
		typedef ft::pair<const Key, Val>			value_type;
		typedef size_t								size_type;
		typedef ptrdiff_t							difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef map<Key, Val, Compare, Allocator>	self;

		typedef value_type&							reference;
		typedef const value_type&					const_reference;

		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			
		protected:
			Compare _comp;

			explicit value_compare(Compare c) : _comp(c) { }
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const
			{ return _comp(x.first, y.first); }
		
		};

		typedef Tree<value_type, allocator_type>				tree_type;
		typedef typename Tree<value_type, allocator_type>::node_pointer 	node_pointer;

		typedef typename tree_type::iterator 		iterator;
		typedef typename tree_type::const_iterator	const_iterator;

		typedef typename tree_type::reverse_iterator 		reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

		/**
		 * @brief Construct a new vector object
		 * 
		 */
		explicit map(const key_compare& comp = key_compare(), 
			const Allocator& alloc = allocator_type())
			: _tree(new tree_type()), _comp(value_compare(comp)), _allocator(alloc) {	}

		template< typename InputIterator >
		map(InputIterator first, InputIterator last,
			   const key_compare& comp = key_compare(),
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0)
			   : _tree(new tree_type()), _comp(value_compare(comp)), _allocator(alloc)
		{
			_tree->assign(first, last, _comp);
		}

		map(const map &other) 
		: _tree(new tree_type()), _comp(other._comp), _allocator(other._allocator)
		{ *this = other; }
		
		virtual ~map() { delete _tree; }
		
		map& operator=(const map &m) 
		{
			_comp = m._comp;
			_tree->assign( m.begin(), m.end(), _comp );
			return *this;
		}

		allocator_type get_allocator() const	{	return this->_allocator; };

		/**
		 * Element access 
		 */

		Val& at(size_type n) 					{	range_check(n); iterator i = begin(); while (n)	{ i++; n--; } return *i; }
		const Val& at(size_type n) const		{	range_check(n); iterator i = begin(); while (n)	{ i++; n--; } return *i; }


		Val& operator[]( const Key& key)		{	

			value_type obj = value_type(key, mapped_type());
			return ((_tree->insert(obj, _comp))->value->second ) ;
		}

		/**
		 * Iterators
		 */
		iterator begin() 						{	return _tree->begin(); }
		const_iterator begin() const			{	return _tree->begin(); }
		iterator end()							{	return _tree->end(); }
		const_iterator end() const				{	return _tree->end(); }
    
		reverse_iterator       rbegin()			{	return _tree->rbegin(); }
		const_reverse_iterator rbegin()  const	{	return _tree->rbegin(); }
		reverse_iterator       rend()			{	return _tree->rend();  }
		const_reverse_iterator rend() const 	{	return _tree->rend();  }

		/**
		 * Capacity
		 */

		bool empty() const						{	return (_tree->size() == 0); }
		size_type size() const					{	return _tree->size(); }
		size_type max_size() const				{	return size_type(_allocator.max_size()); }
				
		/**
		 *  Modifiers 
		 */

		void clear()							{	_tree->clear(); }

		ft::pair<iterator, bool> insert( const value_type& value  ) { return ft::make_pair( iterator(_tree->insert(value, _comp)), true); }

		iterator  insert( iterator position, const value_type &value ) { return  iterator(_tree->insertAt(value, position.base(), _comp)); }

		template< class InputIterator >
		void insert(InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, int >::type = 0)
		{
			for (; first != last; ++first) 
				_tree->insert(*first, _comp);
		}
	
		void erase (iterator pos) { _tree->remove(pos); }
	
		iterator erase (iterator first, iterator last ) { 
			
			iterator tmp;

			while (first != last)
			{
				tmp = first++;
				_tree->removeNode(tmp.base());
			}
			return first;
		 }

		size_type erase( const Key& key ) 
		{ 
			size_type size = _tree->size();
			value_type obj = value_type(key, mapped_type());
			_tree->remove(obj, _comp);
			return (size - _tree->size());
		}
		
		 
		void swap( self& other ) 
		{
			ft::swap(this->_tree, other._tree);
			std::swap(this->_comp, other._comp);
			ft::swap(this->_allocator, other._allocator);
		}
				
		/**
		 *  Lookup 
		 */
		
		size_type count( const Key& key ) const { 
			if(find( key ) != end() )
				return 1;
			return 0;
		}
		
		iterator find( const Key& key ) {
			value_type obj = value_type(key, mapped_type());
			node_pointer node = _tree->find(obj, _comp);
			if(node)
				return iterator(node);
			return (end());
		}

		const_iterator find( const Key& key ) const {
			
			value_type obj = value_type(key, mapped_type());
			node_pointer node = _tree->find(obj, _comp);
			if(node)
				return const_iterator(node);
			return (end());
		}

		ft::pair<iterator,iterator> equal_range( const Key& key ) { return ft::make_pair(lower_bound(key), upper_bound(key));  }
		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const { return ft::make_pair(lower_bound(key), upper_bound(key));  }

		iterator lower_bound( const Key& key ) { 
			
			value_type obj = value_type(key, mapped_type());
			return _tree->lower_bound(_comp, obj);

		 }
		const_iterator lower_bound( const Key& key ) const { 
			
			value_type obj = value_type(key, mapped_type());
			return _tree->lower_bound(_comp, obj);

		}

		iterator upper_bound( const Key& key ) { 
			
			value_type obj = value_type(key, mapped_type());
			return _tree->upper_bound(_comp, obj);

		}
		const_iterator upper_bound( const Key& key ) const { 
						
			value_type obj = value_type(key, mapped_type());
			return _tree->upper_bound(_comp, obj);

		}

		/**
		 *  Observers 
		 */	
		key_compare key_comp() const { return key_compare(); }
		value_compare value_comp() const {  return value_compare(key_comp()); }
	

	protected:

		tree_type		*_tree;
		value_compare	_comp;
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