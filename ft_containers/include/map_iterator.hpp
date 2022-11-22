#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iostream>
#include <memory>
#include "type_traits.hpp"
#include "utility.hpp"
#include "iterator.hpp"


namespace ft
{

	template <bool flag, class const_type, class normal_type>
	struct choose_type;

	template <class const_type, class normal_type>
	struct choose_type<true, const_type, normal_type>
	{
		typedef const_type type;
	};

	template <class const_type, class normal_type>
	struct choose_type<false, const_type, normal_type>
	{
		typedef normal_type type;
	};

	template <typename T>
	struct Node
	{
		typedef Node<T>* pointer;
		typedef const Node<T>* const_pointer;

		bool    _unused;
		pointer	_left;
		pointer	_right;
		pointer	_parent;
		T       _pair;

		static pointer minimum(pointer x)
		{
			while (x->_left != 0) 
				x = x->_left;
			return x;
		}

		static const_pointer minimum(const_pointer x)
		{
			while (x->_left != 0) 
				x = x->_left;
			return x;
		}

		static pointer maximum(pointer x)
		{
			while (x->_right != 0) 
				x = x->_right;
			return x;
		}

		static const_pointer maximum(const_pointer x)
		{
			while (x->_right != 0) 
				x = x->_right;
			return x;
		}		
	};
	
	template<class Key, class T, bool isconst = false>
	struct map_iterator
	{

		typedef map_iterator<Key, T, isconst>                                                       iterator;
		typedef std::ptrdiff_t                                                                      difference_type;
		typedef ft::bidirectional_iterator_tag                                                      iterator_category;
		typedef ft::pair<const Key, T>                                                              value_type;
		typedef typename choose_type<isconst, const value_type&, value_type&>::type                 reference;
		typedef typename choose_type<isconst, const value_type*, value_type*>::type                 pointer;
		typedef typename choose_type<isconst, const Node<value_type>*, Node<value_type>*>::type     nodeptr;

		nodeptr _ptr;

		map_iterator(): _ptr(NULL) {}
		map_iterator(nodeptr ptr): _ptr(ptr) {}
		map_iterator(const map_iterator<Key, T, false> &copy): _ptr(copy._ptr) {}
		map_iterator(const map_iterator<Key, T, true> &copy): _ptr(copy._ptr) {}
		virtual ~map_iterator() {}

		iterator &operator=(const iterator &rhs)
		{
			_ptr = rhs._ptr;
			return *this;
		}
		iterator &operator++()
		{
			if ((_ptr->_right && _ptr->_right->_parent != _ptr) || (_ptr->_left && _ptr->_left->_parent != _ptr))
				_ptr = _ptr->_left;
			else if (_ptr->_right)
			{
				_ptr = _ptr->_right;
				while (_ptr->_left)
					_ptr = _ptr->_left;                
			}
			else
			{
				nodeptr tmp = _ptr->_parent;

				while (_ptr == tmp->_right)
				{
					_ptr = tmp;
					tmp = tmp->_parent;
				}
				if (_ptr->_right != tmp)
					_ptr = tmp;
			}
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			++(*this);
			return tmp;
		}

		iterator &operator--()
		{
			if ((_ptr->_right && _ptr->_right->_parent != _ptr) || (_ptr->_left && _ptr->_left->_parent != _ptr))
				_ptr = _ptr->_right;
			else if (_ptr->_left)
			{
				_ptr = _ptr->_left;
				while (_ptr->_right)
					_ptr = _ptr->_right;                
			}
			else
			{
				nodeptr tmp = _ptr->_parent;

				while (_ptr == tmp->_left)
				{
					_ptr = tmp;
					tmp = tmp->_parent;
				}
				_ptr = tmp;
			}
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			--(*this);
			return tmp;
		}

		bool        operator==(const iterator &rhs) const   {return _ptr == rhs._ptr;}
		bool        operator!=(const iterator &rhs) const   {return _ptr != rhs._ptr;}
		reference   operator*() const                       {return _ptr->_pair;}
		pointer     operator->() const                      {return &_ptr->_pair;}
	};
}

#endif