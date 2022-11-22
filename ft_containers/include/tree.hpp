#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <cstddef>
#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{

	enum Tree_color { tree_color_red = false, tree_color_black = true };

	template<typename T>
	struct Tree_node
	{
		typedef Tree_node<T>* pointer;
		typedef const Tree_node<T>* const_pointer;
	
	public:
		
		Tree_color	color;
		pointer		parent;
		pointer		left;
		pointer		right;

		T value;
		T*	valptr() { return (&value); }
		const T* valptr() const { return (&value); }

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
	bool operator==(const Tree_node<T> &lhs, const Tree_node<T> &rhs)
	{
		return lhs.value == rhs.value;
	}


	template<typename T>
	bool operator!=(const Tree_node<T> &lhs, const Tree_node<T> &rhs)
	{
		return lhs.value != rhs.value;
	}


	template<typename T>
	struct Tree_iterator
	{
		typedef T 									value_type;
		typedef T&									reference;
		typedef T*									pointer;

		typedef ft::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;

		typedef Tree_iterator<T>					self;
		typedef typename Tree_node<T*>::pointer		node_pointer;

		node_pointer _node;

		Tree_iterator() : _node() { }

		Tree_iterator(node_pointer x) : _node(x) { }

		node_pointer	base() const 				{ return _node; }

		reference 	operator*() const 				{ return *(_node->value); }
		pointer		operator->() const				{ return _node->value; }
		self&		operator++()					{ _node = tree_increment(_node); return *this; }
		self		operator++(int)					{ self __tmp = *this; _node = tree_increment(_node); return __tmp; }
		self&		operator--()					{ _node = tree_decrement(_node); return *this; }
		self		operator--(int)					{ self __tmp = *this; _node = tree_decrement(_node); return __tmp; }
		bool		operator==(const self& x) const	{ return _node == x._node; }
		bool		operator!=(const self& x) const	{ return _node != x._node; }
	
	private:

		node_pointer tree_increment(node_pointer node)
		{
			if (node->right != 0) 
			{
				node = node->right;
				while (node->left != 0)
					node = node->left;
			}
			else 
			{
				node_pointer parent = node->parent;
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

		node_pointer tree_decrement(node_pointer node) throw ()
		{
			if (node->color == tree_color_red
				&& node->parent->parent == node)
			node = node->right;
			else if (node->left != 0)
			{
				node_pointer node_left = node->left;
				while (node_left->right != 0)
					node_left = node_left->right;
				node = node_left;
			}
			else
			{
				node_pointer parent = node->parent;
				while (node == parent->left)
				{
					node = parent;
					parent = parent->parent;
				}
				node = parent;
			}
			return node;
		}

	};

  template<typename Val>
    inline bool operator==(const Tree_iterator<Val>& lhs, const Tree_iterator<Val>& rhs)
    { return lhs._node == rhs._node; }

  template<typename Val>
    inline bool operator!=(const Tree_iterator<Val>& lhs, const Tree_iterator<Val>& rhs)
    { return lhs._node != rhs._node; }

	
	template<typename T>
	struct Tree_const_iterator
	{
		typedef T 											value_type;
		typedef const T 									&reference;
		typedef const T 									*pointer;

		typedef ft::bidirectional_iterator_tag				iterator_category;
		typedef ptrdiff_t 									difference_type;

		typedef Tree_iterator<T> 							iterator;
		typedef Tree_const_iterator<T> 						self;
		typedef typename Tree_node<T*>::pointer				node_pointer;
		typedef typename Tree_node<T*>::const_pointer		node_const_pointer;

		Tree_const_iterator() : _node() {}
		Tree_const_iterator(node_const_pointer x) : _node(x) {}
		Tree_const_iterator(const iterator &x): _node(x.base()) { }
		node_const_pointer	base() const 				{ return _node; }
		iterator 	it_const_cast() 			{ return iterator(const_cast< node_pointer >(_node)); }
		reference 	operator*() const			{ return *(_node->value); }
		pointer 	operator->() const 			{ return _node->value; }
		self& 	operator++() 					{ _node = tree_increment(_node); return *this; }
		self 	operator++(int)					{ self tmp = *this;	_node = tree_increment(_node); return tmp; }
		self& 	operator--()					{ _node = tree_decrement(_node); return *this; }
		self 	operator--(int)					{ self tmp = *this;	_node = tree_decrement(_node); return tmp; }

		node_const_pointer _node;

		node_const_pointer tree_increment(node_const_pointer node)
		{
			if (node->right != 0) 
			{
				node = node->right;
				while (node->left != 0)
					node = node->left;
			}
			else 
			{
				node_const_pointer parent = node->parent;
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

		node_const_pointer tree_decrement(node_const_pointer node)
		{
			if (node->color == tree_color_red
				&& node->parent->parent == node)
			node = node->right;
			else if (node->left != 0)
			{
				node_const_pointer node_left = node->left;
				while (node_left->right != 0)
					node_left = node_left->right;
				node = node_left;
			}
			else
			{
				node_const_pointer parent = node->parent;
				while (node == parent->left)
				{
					node = parent;
					parent = parent->parent;
				}
				node = parent;
			}
			return node;
		}		
	};

	template<typename Val>
	bool operator==(const Tree_const_iterator<Val> &lhs, const Tree_const_iterator<Val> &rhs)
	{
		return lhs._node == rhs._node;
	}

	template<typename Val>
	bool operator!=(const Tree_const_iterator<Val> &lhs, const Tree_const_iterator<Val> &rhs)
	{
		return lhs._node != rhs._node;
	}

	template<typename Val>
	bool operator==(const Tree_const_iterator<Val> &lhs, const Tree_iterator<Val> &rhs)
	{
		return lhs._node == rhs._node;
	}

	template<typename Val>
	bool operator==(const Tree_iterator<Val> &lhs, const Tree_const_iterator<Val> &rhs)
	{
		return lhs._node == rhs._node;
	}


	template<typename Val>
	bool operator!=(const Tree_const_iterator<Val> &lhs, const Tree_iterator<Val> &rhs)
	{
		return lhs._node != rhs._node;
	}

	template<typename Val>
	bool operator!=(const Tree_iterator<Val> &lhs, const Tree_const_iterator<Val> &rhs)
	{
		return lhs._node != rhs._node;
	}


/**
 * @brief 
 * 
 * les feuilles sont noires,
 * les fils d'un nœud rouge sont noirs,
 * le nombre de nœuds noirs le long d'une branche de la racine à une feuille est indépendant de la branche.
 * 
 */
 	template<typename T, typename Alloc>
	class Tree
	{
	public:
		typedef T	 											value_type;
		typedef const T& 										reference;
		typedef const T* 										pointer;
		typedef Alloc											allocate_type;
		typedef Tree_node<T*>									node_type;
		typedef Tree_node<T*>*									node_pointer;

		typedef Tree_iterator<T>								iterator;
		typedef Tree_const_iterator<T>							const_iterator;
		typedef typename ft::reverse_iterator< iterator > 		reverse_iterator;
		typedef typename ft::reverse_iterator< const_iterator > const_reverse_iterator;

	private:
		node_pointer	_tree;
		size_t			_count;
		allocate_type	_allocator;

	public:
		Tree() :_tree(0), _count(0), _allocator() { }
		virtual ~Tree() { destroy( _tree ); }
		template< typename Compare >
		node_pointer insert (const T& val, Compare comp) { node_pointer node = insert (val, _tree, comp, NULL); _count++; repareTree(node); return node; }
		template< typename Compare >
		node_pointer insertAt (const T& val, node_pointer n, Compare comp) { node_pointer node = insert (val, n, comp, n->parent); _count++; repareTree(node); return node; }
        void clear (void) { destroy( _tree ); _count = 0; }
		template< typename Compare >
        void remove (const T& val, Compare comp) { node_pointer node = find (val, comp); deleteNode (node) ; };
        void remove (iterator iter) { deleteNode (iter.base()) ; };
		void removeNode (const node_pointer &node) { deleteNode (node) ; };
		template< typename Compare >
		node_pointer find (const T& val, Compare comp) const { return find (val, _tree, comp);	}
		size_t size(void) const { return _count; }
		void prefix (void (*fn)(T &, size_t)) { prefix(_tree, 0, fn); }
		void infix (void (*fn)(T &, size_t)) { infix(_tree, 0, fn); }
		void postfix (void (*fn)(T &, size_t)) { postfix(_tree, 0, fn); }
		void drawTree (size_t level) { draw (_tree, 0, level); }

		iterator  		begin(void) 	 	{ return iterator(node_type::minimum(_tree)); }
		const_iterator  begin(void) const 	{ return const_iterator(node_type::minimum(_tree)); }
		iterator  		end(void) 		 	{ return iterator(node_type::maximum(_tree)); }
		const_iterator  end(void) const 	{ return const_iterator(node_type::maximum(_tree)); }

		reverse_iterator 		rbegin(void) 	 	{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin(void) const 	{ return reverse_iterator(end()); }
		reverse_iterator 		rend(void) 	 		{ return reverse_iterator(begin()); }
		const_reverse_iterator 	rend(void) const 	{ return reverse_iterator(begin()); }
		
		template < class InputIterator , class Compare>
		void assign( InputIterator first, InputIterator last, Compare comp) {
			clear();
			while (first != last)
			{
				insert(*first, comp);
				first++;
			}
		}

		template< typename Compare >
		iterator upper_bound(Compare comp, const value_type &v)
		{
			iterator it = begin();

			while (it != end())
				if (comp(v, *it)) return (it);
				else
					it++;
			return it;
		}

		template< typename Compare >
		const_iterator upper_bound(Compare comp, const value_type &v) const
		{

			const_iterator it = begin();

			while (it != end())
				if (comp(v, *it)) return (it);
				else
					it++;
			return it;
		}

		template< typename Compare >
		iterator lower_bound(Compare comp, const value_type &v)
		{
			iterator it = begin();

			while (it != end())
				if (comp(*it, v)) it++;
				else
					return (it);
			return it;
		}

		template< typename Compare >
		const_iterator lower_bound(Compare comp, const value_type &v) const
		{
			const_iterator it = begin();

			while (it != end())
				if (comp(*it, v)) it++;
				else
					return (it);
			return it;
		}		

	private:



		void draw (node_pointer node, size_t curent_level, size_t level) 
		{ 
			if(!node)
				return ;

			if (curent_level > level)
				return ;

			if (curent_level == level) {
				std::cout << *(node->value) << "\t";
				return ;
			}
			draw (node->left, curent_level + 1, level);
			draw (node->right, curent_level + 1, level);
		}

		void prefix (node_pointer node, size_t level, void (*fn)(T &, size_t)) 
		{ 
			if (!node) 
				return;
			fn(*(node->value), level);
			prefix (node->left, level + 1, fn);
			prefix (node->right, level + 1, fn);
		}

		void infix (node_pointer node, size_t level, void (*fn)(T &, size_t)) 
		{ 
			if (!node) 
				return;
			infix (node->left, level + 1, fn);
			fn(*(node->value), level);
			infix (node->right, level + 1, fn);
		}

		void postfix (node_pointer node, size_t level, void (*fn)(T &, size_t)) 
		{ 
			if (!node) 
				return;
			postfix (node->left, level + 1, fn);
			postfix (node->right, level + 1, fn);
			fn(*(node->value), level);
		}

		void destroy (node_pointer node)
		{
			if (node) {
				destroy (node->left);
				destroy (node->right);
				destroyNode (node);				
			}
		}
		
		void destroyNode (node_pointer node)
		{
			_allocator.destroy(node->value);
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

		void deleteNode (const node_pointer &node)
		{
			if (node) {

				node_pointer parent;

				if (!node->left && !node->right) {
					
					destroyNode(node);

				} else if (node->left && node->right) {

					node_pointer max_node = node->maximum(node->left);
					T* temp = node->value;
					node->value = max_node->value;
					max_node->value = temp;

					deleteNode (max_node);

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
					destroyNode (node);
				}
			}
		}

		template< typename Compare >
		node_pointer insert (const T& val, node_pointer& node, Compare comp, node_pointer parent)
		{
			if (!node) {
				node = createNode(val);
				node->parent = parent;
				return node;
			}
			else {
				if ( comp(val, *node->value) ) {
					return insert (val, node->left, comp, node);
				}
				else {
					return insert (val, node->right, comp, node);
				}
			}
		}

		template< typename Compare >
		node_pointer find (const T& val, node_pointer node, Compare comp) const {
			
			if (!node) {
				return NULL;
			}

			if (comp(val, *(node->value))) {
				return find (val, node->left, comp);
			}
			else if (comp(*(node->value), val)) {
				return find (val, node->right, comp);
			}
			else {
				return node;
			}
		}

		node_pointer createNode (const T& val) {

			node_pointer node = new node_type();
			node->value = _allocator.allocate(1);
			_allocator.construct(node->value, val);
			node->left = NULL;
			node->right = NULL;
			node->color = tree_color_red;
			node->parent = NULL;
			return node;
		}

	public: 
		/**
		 * rotation à droite :
		 * 
		 *          t                         l
		 *         / \                       / \
		 *        l   z     ========>       x   t
		 *       / \                           / \
		 *      x   y                         y   z
		 *
		 *   t = node 
		 *   l = node->left -> root
		 *   z = node->right
		 * 
		 */
		node_pointer rotateRight(node_pointer node)
		{
			node_pointer root = node->left;
			
			// déplacement de la référence du parent
			if (node == _tree) {
				_tree = root;
				root->parent = NULL;
			}
			else {
				node_pointer& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;
				parent_link = root;
				root->parent = node->parent;
			}

			// Rotation 
			node->parent = root;
			node->left = root->right;
			if (node->left)
				node->left->parent = node;
			root->right = node;

			return root;
		}

		/**
		 * rotation à gauche :
		 * 
		 *       l                     t   
		 *      / \                   / \  
		 *     x   t    ========>    l   z 
		 *        / \               / \    
		 *       y   z             x   y   
		 *
		 *   l = node 
		 *   t = node->right -> root
		 *   x = node->left
		 * 
		 */
		node_pointer rotateLeft(node_pointer node)
		{
			node_pointer root = node->right;
			
			// déplacement de la référence du parent
			if (node == _tree) {
				_tree = root;
				root->parent = NULL;
			}
			else {
				node_pointer& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;
				parent_link = root;
				root->parent = node->parent;
			}

			// Rotation 
			node->parent = root;
			node->right = root->left;
			if (node->right)
				node->right->parent = node;
			root->left = node;

			return root;
		}


		node_pointer parent(node_pointer node) {
			return node->parent;
		}

		node_pointer grandparent(node_pointer node) {
			node_pointer p = parent(node);
			if (p == NULL)
				return NULL; // Un noeud sans parent n'a pas de grand-parent
			return parent(p);
		}

		node_pointer brother(node_pointer node) {
			node_pointer p = parent(node);
			if (p == NULL)
				return NULL; // Un noeud sans parent n'a pas de frere
			if (node == p->left)
				return p->right;
			else
				return p->left;
		}

		//Renvoie le frère du père
		node_pointer uncle(node_pointer node) {
			node_pointer p = parent(node);
			node_pointer g = grandparent(node);
			if (g == NULL)
				return NULL; // Pas de grand parent, donc pas d'oncle
			return brother(p);
		}		

		void repareTree(node_pointer node) 
		{
			node_pointer gp;
			node_pointer p;

			if (node == _tree) {
				node->color = tree_color_black;
				return ;
			}
			if (node->parent->color == tree_color_black) {
				/* Ne rien faire puisque l'arbre est bien un arbre rouge-noir */
				return ;
			}

			node_pointer u = uncle(node);

			if ( u != NULL && u->color == tree_color_red) {
				parent(node)->color = tree_color_black;
   				uncle(node)->color = tree_color_black;

				gp = grandparent(node);
				gp->color = tree_color_red;
				repareTree(gp);
				return ;
			}


			p = parent(node);
			gp = grandparent(node);

			if (gp->left != NULL && node == gp->left->right) {
				rotateLeft(p);
				node = node->left;
			} else if (gp->right != NULL && node == gp->right->left) {
				rotateRight(p);
				node = node->right; 
			}
		/*
		 *       gp                    p   
		 *      / \                   / \  
		 *     p   u    ========>    n   gp 
		 *    / \                         \ 
		 *   n                             u
		 */

			p = parent(node);
			gp = grandparent(node);

			if (node == p->left)
				rotateRight(gp);
			else
				rotateLeft(gp);
			
			p->color = tree_color_black;
			gp->color = tree_color_red;

		};

	};

}

#endif