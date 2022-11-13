#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <cstddef>
#include <memory>
#include "iterator.hpp"

namespace ft
{

	enum Tree_color { tree_color_red = false, tree_color_black = true };

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

/*
	struct Tree_header
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
*/


	template<typename T>
	struct Tree_iterator
	{
		typedef T 								value_type;
		typedef T&								reference;
		typedef T*								pointer;

		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;

		typedef Tree_iterator<T>				self;
		typedef Tree_node_base::pointer			tree_pointer;
		typedef Tree_node<T*>*					link_type;

		tree_pointer _node;

		Tree_iterator() : _node() { }

		Tree_iterator(tree_pointer x) : _node(x) { }

		reference 	operator*() const 				{ return **static_cast<link_type>(_node)->valptr(); }
		pointer		operator->() const				{ return *static_cast<link_type> (_node)->valptr(); }
		self&		operator++()					{ _node = tree_increment(_node); return *this; }
		self		operator++(int)					{ self __tmp = *this; _node = tree_increment(_node); return __tmp; }
		self&		operator--()					{ _node = tree_decrement(_node); return *this; }
		self		operator--(int)					{ self __tmp = *this; _node = tree_decrement(_node); return __tmp; }
		bool		operator==(const self& x) const	{ return _node == x._node; }
		bool		operator!=(const self& x) const	{ return _node != x._node; }
	
	private:

		tree_pointer tree_increment(tree_pointer node)
		{
			if (node->right != 0) 
			{
				node = node->right;
				while (node->left != 0)
					node = node->left;
			}
			else 
			{
				tree_pointer parent = node->parent;
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

		tree_pointer tree_decrement(tree_pointer node) throw ()
		{
			if (node->color == tree_color_red
				&& node->parent->parent == node)
			node = node->right;
			else if (node->left != 0)
			{
				tree_pointer node_left = node->left;
				while (node_left->right != 0)
					node_left = node_left->right;
				node = node_left;
			}
			else
			{
				tree_pointer parent = node->parent;
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

  template<typename _Val>
    inline bool operator==(const Tree_iterator<_Val>& a, const Tree_iterator<_Val>& b)
    { return a._node == b._node; }

  template<typename _Val>
    inline bool operator!=(const Tree_iterator<_Val>& a, const Tree_iterator<_Val>& b)
    { return a._node != b._node; }


/*	
	template<typename _Tp>
	struct Rb_tree_const_iterator
	{
		typedef _Tp	 								value_type;
		typedef const _Tp& 							reference;
		typedef const _Tp* 							pointer;
		typedef Tree_iterator<_Tp> 					iterator;

		typedef ft::bidirectional_iterator_tag 		iterator_category;
		typedef ptrdiff_t			 				difference_type;

		typedef Rb_tree_const_iterator<_Tp>			self;
		typedef Tree_node_base::const_pointer		tree_pointer;
		typedef const Tree_node<_Tp>*				link_type;
	
		tree_pointer _node;

		Rb_tree_const_iterator() : _node() { }

		Rb_tree_const_iterator(pointer x) : _node(x) { }

		Rb_tree_const_iterator(const iterator& __it) : _node(__it._node) { }

		reference	operator*() const					{ return *static_cast<link_type>(_node)->valptr(); }
		pointer		operator->() const					{ return static_cast<link_type>(_node)->valptr(); }
		self&		operator++()						{ _node = tree_increment(_node); return *this; }
		self		operator++(int)						{ self __tmp = *this; _node = tree_increment(_node); return __tmp; }
		self&		operator--()						{ _node = tree_decrement(_node); return *this; }
		self		operator--(int)						{ self __tmp = *this; _node = tree_decrement(_node); return __tmp; }
		friend bool	operator==(const self& x, const self& y) { return x._node == y._node; }
		friend bool	operator!=(const self& x, const self& y) { return x._node != y._node; }

	private:

		tree_pointer tree_increment(tree_pointer node)
		{
			if (node->right != 0) 
			{
				node = node->right;
				while (node->left != 0)
					node = node->left;
			}
			else 
			{
				tree_pointer parent = node->parent;
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

		tree_pointer tree_decrement(tree_pointer node) throw ()
		{
			if (node->color == tree_color_red
				&& node->parent->parent == node)
			node = node->right;
			else if (node->left != 0)
			{
				tree_pointer node_left = node->left;
				while (node_left->right != 0)
					node_left = node_left->right;
				node = node_left;
			}
			else
			{
				tree_pointer parent = node->parent;
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

*/

/**
 * @brief 
 * 
 * les feuilles sont noires,
 * les fils d'un nœud rouge sont noirs,
 * le nombre de nœuds noirs le long d'une branche de la racine à une feuille est indépendant de la branche.
 * 
 */
 	template<typename T, typename Alloc >
	class Tree
	{
	public:
		typedef T	 						value_type;
		typedef const T& 					reference;
		typedef const T* 					pointer;
		typedef Alloc						allocate_type;
		typedef Tree_node<T*>				node_type;
		typedef Tree_node_base::pointer		tree_pointer;
		typedef Tree_node<T*>*				link_type;

		typedef Tree_iterator<T>			iterator;

	private:
		tree_pointer	_tree;
		size_t			_count;
		allocate_type	_allocator;

	public:
		Tree() :_tree(0), _count(0), _allocator() { }
		virtual ~Tree() { destroy( _tree ); }
        void insert (const T& val) { tree_pointer node = insert (val, _tree, NULL); _count++; repareTree(node); }
        void destroy (void) { destroy( _tree ); _count = 0; }
        void remove (const T& val) { tree_pointer node = search (val); deleteNode (node) ; };
		tree_pointer search (const T& val) const { return search (val, _tree);	}
		size_t size(void) const { return _count; }
		void prefix (void (*fn)(T &, size_t)) { prefix(_tree, 0, fn); }
		void infix (void (*fn)(T &, size_t)) { infix(_tree, 0, fn); }
		void postfix (void (*fn)(T &, size_t)) { postfix(_tree, 0, fn); }
		void drawTree (size_t level) { draw (_tree, 0, level); }
		iterator  begin(void) const { return iterator(node_type::minimum(_tree)); }
		iterator  end(void) const { return iterator(node_type::maximum(_tree)); }

	private:

		void draw (tree_pointer node, size_t curent_level, size_t level) 
		{ 
			if(!node)
				return ;

			if (curent_level > level)
				return ;

			if (curent_level == level) {
				std::cout << *(static_cast<link_type>(node)->value) << "\t";
				return ;
			}
			draw (node->left, curent_level + 1, level);
			draw (node->right, curent_level + 1, level);
		}

		void prefix (tree_pointer node, size_t level, void (*fn)(T &, size_t)) 
		{ 
			if (!node) 
				return;
			fn(*(static_cast<link_type>(node)->value), level);
			prefix (node->left, level + 1, fn);
			prefix (node->right, level + 1, fn);
		}

		void infix (tree_pointer node, size_t level, void (*fn)(T &, size_t)) 
		{ 
			if (!node) 
				return;
			infix (node->left, level + 1, fn);
			fn(*(static_cast<link_type>(node)->value), level);
			infix (node->right, level + 1, fn);
		}

		void postfix (tree_pointer node, size_t level, void (*fn)(T &, size_t)) 
		{ 
			if (!node) 
				return;
			postfix (node->left, level + 1, fn);
			postfix (node->right, level + 1, fn);
			fn(*(static_cast<link_type>(node)->value), level);
		}

		void destroy (tree_pointer node)
		{
			if (node) {
				destroy (node->left);
				destroy (node->right);
				destroyNode (node);				
			}
		}
		
		void destroyNode (tree_pointer node)
		{
			_allocator.destroy(static_cast<link_type>(node)->value);
			_allocator.deallocate(static_cast<link_type>(node)->value, 1);
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

		void deleteNode (tree_pointer &node)
		{
			if (node) {

				tree_pointer parent;

				if (!node->left && !node->right) {
					
					destroyNode(node);

				} else if (node->left && node->right) {

					tree_pointer max_node = node->maximum(node->left);
					T* temp = static_cast<link_type>(node)->value;
					static_cast<link_type>(node)->value = static_cast<link_type>(max_node)->value;
					static_cast<link_type>(max_node)->value = temp;

					deleteNode (max_node);

				} else {

			        tree_pointer child = (node->left) ? node->left : node->right;  
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

		tree_pointer insert (const T& val, tree_pointer& node, tree_pointer parent)
		{
			if (!node) {
				node = createNode(val);
				node->parent = parent;
				return node;
			}
			else {
				if ( val < *static_cast<link_type>(node)->value ) {
					return insert (val, node->left, node);
				}
				else {
					return insert (val, node->right, node);
				}
			}
		}

		tree_pointer search (const T& val, tree_pointer node) const {
			
			if (!node) {
				return NULL;
			}
			else if (*(static_cast<link_type>(node)->value) == val){
				return node;
			}
			else if (val < *(static_cast<link_type>(node)->value)){
				return search (val, node->left);
			}
			else{
				return search (val, node->right);
			}
		}

		tree_pointer createNode (const T& val) {

			tree_pointer node = new node_type();
			static_cast<link_type>(node)->value = _allocator.allocate(1);
			_allocator.construct(static_cast<link_type>(node)->value, val);
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
		tree_pointer rotateRight(tree_pointer node)
		{
			tree_pointer root = node->left;
			
			// déplacement de la référence du parent
			if (node == _tree) {
				_tree = root;
				root->parent = NULL;
			}
			else {
				tree_pointer& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;
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
		tree_pointer rotateLeft(tree_pointer node)
		{
			tree_pointer root = node->right;
			
			// déplacement de la référence du parent
			if (node == _tree) {
				_tree = root;
				root->parent = NULL;
			}
			else {
				tree_pointer& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;
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


		tree_pointer parent(tree_pointer node) {
			return node->parent;
		}

		tree_pointer grandparent(tree_pointer node) {
			tree_pointer p = parent(node);
			if (p == NULL)
				return NULL; // Un noeud sans parent n'a pas de grand-parent
			return parent(p);
		}

		tree_pointer brother(tree_pointer node) {
			tree_pointer p = parent(node);
			if (p == NULL)
				return NULL; // Un noeud sans parent n'a pas de frere
			if (node == p->left)
				return p->right;
			else
				return p->left;
		}

		//Renvoie le frère du père
		tree_pointer uncle(tree_pointer node) {
			tree_pointer p = parent(node);
			tree_pointer g = grandparent(node);
			if (g == NULL)
				return NULL; // Pas de grand parent, donc pas d'oncle
			return brother(p);
		}		

		void repareTree(tree_pointer node) 
		{
			tree_pointer gp;
			tree_pointer p;

			if (node == _tree) {
				node->color = tree_color_black;
				return ;
			}
			if (node->parent->color == tree_color_black) {
				/* Ne rien faire puisque l'arbre est bien un arbre rouge-noir */
				return ;
			}

			tree_pointer u = uncle(node);

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