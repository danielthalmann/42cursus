#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>


namespace ft
{

	enum Rb_tree_color { _S_red = false, _S_black = true };

	struct Rb_tree_node_base
	{
		typedef Rb_tree_node_base*			Base_ptr;
		typedef const Rb_tree_node_base* 	ConstBase_ptr;

		Rb_tree_color	_M_color;
		Base_ptr		_M_parent;
		Base_ptr		_M_left;
		Base_ptr		_M_right;

		static Base_ptr minimum(Base_ptr x)
		{
			while (x->_M_left != 0) 
				x = x->_M_left;
			return x;
		}

		static ConstBase_ptr minimum(ConstBase_ptr x)
		{
			while (x->_M_left != 0) 
				x = x->_M_left;
			return x;
		}

		static Base_ptr maximum(Base_ptr x)
		{
			while (x->_M_right != 0) 
				x = x->_M_right;
			return x;
		}

		static ConstBase_ptr maximum(ConstBase_ptr x)
		{
			while (x->_M_right != 0) 
				x = x->_M_right;
			return x;
		}
	
	};

	template<typename _Key_compare>
	struct _Rb_tree_key_compare
	{
		_Key_compare		_M_key_compare;

		_Rb_tree_key_compare()
		: _M_key_compare()
		{ }

		_Rb_tree_key_compare(const _Key_compare& __comp)
		: _M_key_compare(__comp)
		{ }
	};


	// Helper type to manage default initialization of node count and header.
	struct _Rb_tree_header
	{
		Rb_tree_node_base	_M_header;
		size_t				_M_node_count; // Keeps track of size of tree.

		_Rb_tree_header()
		{
			_M_header._M_color = _S_red;
			_M_reset();
		}


		void _M_move_data(_Rb_tree_header& __from)
		{
			_M_header._M_color = __from._M_header._M_color;
			_M_header._M_parent = __from._M_header._M_parent;
			_M_header._M_left = __from._M_header._M_left;
			_M_header._M_right = __from._M_header._M_right;
			_M_header._M_parent->_M_parent = &_M_header;
			_M_node_count = __from._M_node_count;

			__from._M_reset();
		}

		void
		_M_reset()
		{
			_M_header._M_parent = 0;
			_M_header._M_left = &_M_header;
			_M_header._M_right = &_M_header;
			_M_node_count = 0;
		}
	};

	template<typename _Tp>
	struct _Rb_tree_iterator
	{
		typedef _Tp  value_type;
		typedef _Tp& reference;
		typedef _Tp* pointer;

		typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t                  difference_type;

		typedef _Rb_tree_iterator<_Tp>        _Self;
		typedef _Rb_tree_node_base::_Base_ptr _Base_ptr;
		typedef _Rb_tree_node<_Tp>*           _Link_type;

		_Rb_tree_iterator()
		: _M_node() { }

		explicit
		_Rb_tree_iterator(_Base_ptr __x)
		: _M_node(__x) { }

		reference
		operator*() const
		{ return *static_cast<_Link_type>(_M_node)->_M_valptr(); }

		pointer
		operator->() const
		{ return static_cast<_Link_type> (_M_node)->_M_valptr(); }

		_Self&
		operator++()
		{
		_M_node = _Rb_tree_increment(_M_node);
		return *this;
		}

		_Self
		operator++(int)
		{
		_Self __tmp = *this;
		_M_node = _Rb_tree_increment(_M_node);
		return __tmp;
		}

		_Self&
		operator--()
		{
		_M_node = _Rb_tree_decrement(_M_node);
		return *this;
		}

		_Self
		operator--(int)
		{
		_Self __tmp = *this;
		_M_node = _Rb_tree_decrement(_M_node);
		return __tmp;
		}

		bool
		operator==(const _Self& __x) const
		{ return _M_node == __x._M_node; }

		bool
		operator!=(const _Self& __x) const
		{ return _M_node != __x._M_node; }

		_Base_ptr _M_node;
	};

}

#endif