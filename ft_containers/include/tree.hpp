#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>
#include <memory>
#include "iterator.hpp"

namespace ft
{

	enum Tree_color { S_red = false, S_black = true };

	struct Tree_node_base
	{
		typedef Tree_node_base*			pointer;
		typedef const Tree_node_base* 	const_pointer;

		Tree_color	color;
		pointer		parent;
		pointer		left;
		pointer		right;

		static pointer minimum(pointer x)
		{
			while (x->left != 0) 
				x = x->left;
			return x;
		}

		static const_pointer minimum(const_pointer x)
		{
			while (x->left != 0) 
				x = x->left;
			return x;
		}

		static pointer maximum(pointer x)
		{
			while (x->right != 0) 
				x = x->right;
			return x;
		}

		static const_pointer maximum(const_pointer x)
		{
			while (x->right != 0) 
				x = x->right;
			return x;
		}
	
	};
	template<typename T>
	struct Tree_node : public Tree_node_base
	{
		typedef Tree_node<T>* link_type;
		T value;
		T*	valptr() { return (&value); }
		const T* valptr() const { return (&value); }
	};

	class Tree_header
	{
		Tree_node_base	header;
		size_t			count;

		Tree_header()
		{
			header.color = S_red;
			reset();
		}

		void move_data(Tree_header& from)
		{
			header.color = from.header.color;
			header.parent = from.header.parent;
			header.left = from.header.left;
			header.right = from.header.right;
			header.parent->parent = &header;
			count = from.count;

			from.reset();
		}

		void reset()
		{
			header.parent = 0;
			header.left = 0;
			header.right = 0;
			count = 0;
		}
	};

	static Tree_node_base* local_increment(Tree_node_base* node)
	{
		if (node->right != 0) 
		{
			node = node->right;
			while (node->left != 0)
				node = node->left;
		}
		else 
		{
			Tree_node_base* parent = node->parent;
			while (node == parent->right) 
			{
				node = parent;
				parent = parent->parent;
			}
			if (node->right != parent)
					node = parent;
		}
		return node;
	}

	Tree_node_base* _Rb_tree_increment(Tree_node_base* __x) 
	{
		return local_increment(__x);
	}

	const Tree_node_base* _Rb_tree_increment(const Tree_node_base* __x) 
	{
		return local_increment(const_cast<Tree_node_base*>(__x));
	}


	template<typename _Tp>
	struct Rb_tree_iterator
	{
		typedef _Tp 							value_type;
		typedef _Tp&							reference;
		typedef _Tp*							pointer;

		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;

		typedef Rb_tree_iterator<_Tp>			self;
		typedef Tree_node_base::pointer			tree_pointer;
		typedef Tree_node<_Tp>*					link_type;

		pointer _node;

		Rb_tree_iterator() : _node() { }

		Rb_tree_iterator(pointer x) : _node(x) { }

		reference 	operator*() const 				{ return *static_cast<link_type>(_node)->valptr(); }
		pointer		operator->() const				{ return static_cast<link_type> (_node)->valptr(); }
		self&		operator++()					{ _node = tree_increment(_node); return *this; }
		self		operator++(int)					{ self __tmp = *this; _node = _Rb_tree_increment(_node); return __tmp; }
		self&		operator--()					{ _node = tree_decrement(_node); return *this; }
		self		operator--(int)					{ self __tmp = *this; _node = _Rb_tree_decrement(_node); return __tmp; }
		bool		operator==(const self& x) const	{ return _node == x._node; }
		bool		operator!=(const self& x) const	{ return _node != x._node; }
	
	private:


	};
	
	template<typename _Tp>
	struct Rb_tree_const_iterator
	{
		typedef _Tp	 								value_type;
		typedef const _Tp& 							reference;
		typedef const _Tp* 							pointer;
		typedef Rb_tree_iterator<_Tp> 				iterator;

		typedef ft::bidirectional_iterator_tag 		iterator_category;
		typedef ptrdiff_t			 				difference_type;

		typedef Rb_tree_const_iterator<_Tp>			self;
		typedef Tree_node_base::const_pointer		tree_pointer;
		typedef const Tree_node<_Tp>*				link_type;
	
		pointer _node;

		Rb_tree_const_iterator() : _node() { }

		Rb_tree_const_iterator(pointer x) : _node(x) { }

		Rb_tree_const_iterator(const iterator& __it) : _node(__it._node) { }

		reference	operator*() const					{ return *static_cast<link_type>(_node)->valptr(); }
		pointer		operator->() const					{ return static_cast<link_type>(_node)->valptr(); }
		self&		operator++()						{ _node = tree_increment(_node); return *this; }
		self		operator++(int)						{ self __tmp = *this; _node = _Rb_tree_increment(_node); return __tmp; }
		self&		operator--()						{ _node = tree_decrement(_node); return *this; }
		self		operator--(int)						{ self __tmp = *this; _node = _Rb_tree_decrement(_node); return __tmp; }
		friend bool	operator==(const self& x, const self& y) { return x._node == y._node; }
		friend bool	operator!=(const self& x, const self& y) { return x._node != y._node; }

	private:


	};

	template<typename T, typename Alloc >
	class Tree
	{
		typedef Alloc			allocate_type;
		typedef Tree_node<T*>	node_type;
		typedef Tree_node<T*>*	node_pointer;
		
	private:
		node_pointer	_tree;
		allocate_type	_allocator;
		size_t			_count;

	public:
		Tree() :_tree(0), _count(0), _allocator() { }

        void insert (const T& val) { insert (val, _tree, NULL); _count++; }
        void destroy () { destroy( _tree ); _count = 0; }
        void remove (const T& val);
		node_pointer search (const T& val) const { return search (val, _tree);	}

	private:

		void destroy (node_pointer &node)
		{
			if (node) {
				destroy (node->left);
				destroy (node->right);
				destroyNode (node);				
			}
		}
		
		void destroyNode (node_pointer &node)
		{
			_allocator.detroy(node->value);
			_allocator.deallocate(node->value, 1);
			_count--;
			if (node->parent) {
				if (node->parent->left == node)
					node->parent->left = NULL;
				else if (node->parent->right == node)
					node->parent->right = NULL;
			}
			if (_tree == node)
				_tree = NULL;
			delete node;
		}

		void deleteNode (node_pointer &node)
		{
			if (node) {

				node_pointer parent;

				if (!node->left && !node->right) {
					
					destroyNode (node_pointer &node);

				} else if (node->left && node->right) {

					node->maximum()

				} else {

			        node_pointer child = (node->left) ? node->left : node->right;  
					parent = node->parent;

					if (parent)
					{
						if (parent->left == node) {
							parent->left = child;
						}
						else if (parent->right == node) {
							parent->right = child;	
						}
						child->parent = parent;
					}
					destroyNode (node_pointer &node);
				}
			}
		}

		void insert (const T& val, node_pointer &node, node_pointer &parent)
		{
			if (!node) {
				node = createNode(val);
				node->parent = parent;
			}
			else {
				if (val < node->value) {
					insert (val, node->left, node);
				}
				else {
					insert (val, node->right, node);
				}
			}
		}

		node_pointer search (const T& val, node_pointer ptr) const {
			
			if (!ptr) {
				return NULL;
			}
			else if ((ptr->value) == valeur){
				return ptr;
			}
			else if (valeur < (ptr->value)){
				return search (val, ptr->left);
			}
			else{
				return search (val, ptr->right);
			}
		}

		node_pointer createNode (const T& val) {

			node_pointer node = new node_type();
			node->value = _allocator.allocate(1);
			_allocator.construct(node->value, val);
			node->left = NULL;
			node->right = NULL;
			node->parent = NULL;
			return node;
		}

	}

}

#endif