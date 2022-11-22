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
#include "map_iterator.hpp"


namespace ft
{
	template <class Compare, class T>
	class Comp {
	public:

		Compare _comp;

		Comp(Compare c) : _comp(c) {}

		bool operator()(const T& x, const T& y) const { return _comp(x.first, y.first); }
	};

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:

			typedef Key                                                     key_type;
			typedef T                                                       mapped_type;
			typedef ft::pair<const key_type, mapped_type>                   value_type;
			typedef Compare                                                 key_compare;
			typedef ft::Comp<Compare, value_type>                           value_compare;
			typedef Alloc                                                   allocator_type;
			typedef typename allocator_type::reference                      reference;
			typedef typename allocator_type::const_reference                const_reference;
			typedef typename allocator_type::pointer                        pointer;
			typedef typename allocator_type::const_pointer                  const_pointer;

			typedef ft::map_iterator<key_type, mapped_type>                 iterator;
			typedef ft::map_iterator<key_type, mapped_type, true>           const_iterator;
			typedef ft::reverse_iterator<iterator>                          reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;

			typedef std::ptrdiff_t                                          difference_type;
			typedef std::size_t                                             size_type;
			typedef Node<value_type>                                        node_type;
			typedef typename Alloc:: template rebind<node_type>::other      alloc_node_type;

		private:


			alloc_node_type             _alloc_node;
			allocator_type              _alloc;
			key_compare                 _comp;
			size_type                   _size;
			node_type                  *_container;

		private:

			node_type *get_root() const { return _container->_parent; }
			node_type *get_left() const { return _container->_left; }
			node_type *get_right() const { return _container->_right; }

			node_type	*insert_node(node_type *node, key_compare comp, value_type pair)
			{
				if (node == _container) 
				{
					if (!node->_parent) 
					{
						node->_parent = _alloc_node.allocate(1);
						node->_parent->_left = NULL;
						node->_parent->_right = NULL;
						node->_parent->_parent = node;
						_alloc.construct(&node->_parent->_pair, pair);

						set_left_right();
						return node->_parent;
					}
					else
						node = node->_parent;
				}
				if (comp(pair.first, node->_pair.first))
				{
					if (!node->_left) 
					{
						node->_left = _alloc_node.allocate(1);
						node->_left->_left = NULL;
						node->_left->_right = NULL;
						node->_left->_parent = node;
						_alloc.construct(&node->_left->_pair, pair);

						set_left_right();
						return node->_left;
					}
					else
						node = insert_node(node->_left, comp, pair);
				}
				else
				{
					if (!node->_right) 
					{
						node->_right = _alloc_node.allocate(1);
						node->_right->_left = NULL;
						node->_right->_right = NULL;
						node->_right->_parent = node;
						_alloc.construct(&node->_right->_pair, pair);

						set_left_right();
						return node->_right;
					}
					else
						node = insert_node(node->_right, comp, pair);
				}
				return node;
			}

			void  set_left_right()
			{
				node_type *tmp = get_root();

				if (!tmp) {
					_container->_left = _container;
					_container->_right = _container;
					return ;
				}
				while (tmp && tmp->_left)
					tmp = tmp->_left;
				_container->_left = tmp;

				tmp = get_root();
				while (tmp && tmp->_right)
					tmp = tmp->_right;
				_container->_right = tmp;
			}

			node_type *key_exists_recurse(node_type *node, key_type key) const 
			{
				if (!node) {
					return NULL;
				}

				if (_comp(key, (node->_pair.first))) {
					return key_exists_recurse (node->_left, key);
				}
				else if (_comp((node->_pair.first), key)) {
					return key_exists_recurse (node->_right, key);
				}
				else {
					return node;
				}
			}

			size_type key_count_recurse(node_type *root, key_type key) const 
			{
				if (!root)
					return 0;
				if (!_comp(root->_pair.first, key) && !_comp(key, root->_pair.first))
					return 1;
				return key_count_recurse(root->_left, key) + key_count_recurse(root->_right, key);
			}

		public:

			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _size(0)
			{
				_container = _alloc_node.allocate(1);
				_container->_left = NULL;
				_container->_right = NULL;
				_container->_parent = NULL;
				_alloc.construct(&_container->_pair, value_type());
			}

			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _size(0)
			{
				_container = _alloc_node.allocate(1);
				_container->_left = NULL;
				_container->_right = NULL;
				_container->_parent = NULL;
				_alloc.construct(&_container->_pair, value_type());

				insert(first, last);
			}

			map(const map &copy)
			: _alloc(copy._alloc), _comp(copy._comp), _size(0)
			{
				_container = _alloc_node.allocate(1);
				_container->_left = NULL;
				_container->_right = NULL;
				_container->_parent = NULL;
				_alloc.construct(&_container->_pair, value_type());

				insert(copy.begin(), copy.end());
			}

			~map()
			{
				clear();
				_alloc.destroy(&_container->_pair);
				_alloc_node.deallocate(_container, 1);
			}

			map & operator=(const map& rhs)
			{
				clear();
				insert(rhs.begin(), rhs.end());
				return *this;
			}

			iterator begin() { return iterator(node_type::minimum(_container)); }
			iterator end() { return iterator(node_type::maximum(_container)); }
			const_iterator begin() const { return const_iterator(get_left()); }
			const_iterator end() const { return const_iterator(_container); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			}

			bool        empty() const     { return begin() == end(); };
			size_type   size() const      { return _size; };
			size_type   max_size() const  { return _alloc_node.max_size(); };

			pair<iterator, bool> insert (const value_type& val) 
			{
				node_type *exist = key_exists_recurse(get_root(), val.first);

				if (exist)
					return ft::make_pair(iterator(exist), false);
				_size++;
				return ft::make_pair(iterator(insert_node(_container, _comp, val)), true);
			}

			iterator insert (iterator position, const value_type& val) 
			{
				(void)position;
				node_type *exist = key_exists_recurse(get_root(), val.first);

				if (exist)
					return iterator(exist);
				_size++;
				return iterator(insert_node(_container, _comp, val));
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
			{

				while (first != last) {
					insert(*first);
					++first;
				}
			}

			void      erase(iterator position) 
			{
				node_type *current = position._ptr;
				node_type *tmp = NULL;

				if (current->_left)
				{
					tmp = current->_left;
					while (tmp->_right)
						tmp = tmp->_right;
					if (tmp->_parent->_right == tmp)
					{
						if (tmp->_left)
						{
							tmp->_parent->_right = tmp->_left;
							tmp->_left->_parent = tmp->_parent;
						}
						else
							tmp->_parent->_right = NULL;
					}
					tmp->_right = current->_right;
					if (current->_right)
						current->_right->_parent = tmp;
					if (current->_left != tmp)
						tmp->_left = current->_left;
					if (current->_left)
						current->_left->_parent = tmp;
					tmp->_parent = current->_parent;
				}
				else if (current->_right)
				{
					tmp = current->_right;
					tmp->_parent = current->_parent;
				}
				if (current->_parent->_left == current)
					current->_parent->_left = tmp;
				else
					current->_parent->_right = tmp;
				if (current == get_root())
					_container->_parent = tmp;
				_alloc.destroy(&current->_pair);
				_alloc_node.deallocate(current, 1);
				_size--;
				set_left_right();
			}

			size_type erase(const key_type& k)
			{
				iterator it = begin();
				iterator tmp;
				size_type count = 0;
			
				while (it != end()) 
				{
					if (!_comp(it->first, k) && !_comp(k, it->first)) 
					{
						erase(it);
						count++;
						return count;
					}
					else
						it++;
				}
				return count;
			}

			void      erase(iterator first, iterator last)
			{
				iterator tmp;

				while (first != last)
				{
					tmp = first++;
					erase(tmp);
				}
			}

			void swap (map& x)
			{
				node_type *tmp;
				size_type size_tmp;

				size_tmp = _size;
				_size = x._size;
				x._size = size_tmp;

				tmp = _container;
				_container = x._container;
				x._container = tmp;
			}

			void clear() { erase(begin(), end()); }

			key_compare key_comp() const { return key_compare(); }
			value_compare value_comp() const { return value_compare(key_compare()); }

			iterator find (const key_type& k)
			{
				node_type *found = key_exists_recurse(get_root(), k);

				if (found)
					return iterator(found);
				return (end());
			}

			const_iterator find (const key_type& k) const
			{
				node_type *found = key_exists_recurse(get_root(), k);

				if (found)
					return const_iterator(found);
				return (end());
			}

			size_type count (const key_type& k) const
			{
				return key_count_recurse(get_root(), k);
			}

			iterator        lower_bound (const key_type& k)
			{
				iterator it = begin();

				while (it != end())
				{
					if (!_comp(it->first, k))
						return it;
					it++;
				}
				return it;
			}
			const_iterator  lower_bound (const key_type& k) const
			{
				const_iterator it = begin();

				while (it != end())
				{
					if (!_comp(it->first, k))
						return it;
					it++;
				}
				return it;
			}

			iterator        upper_bound (const key_type& k)
			{
				iterator it = begin();

				while (it != end())
				{
					if (_comp(k, it->first))
						return it;
					it++;
				}
				return it;
			}
			const_iterator  upper_bound (const key_type& k) const
			{
				const_iterator it = begin();

				while (it != end())
				{
					if (_comp(k, it->first))
						return it;
					it++;
				}
				return it;
			}

			ft::pair<iterator, iterator>    equal_range (const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const 
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}
	};

	template <class Key, class T>
	bool operator==(const map<Key, T>& lhs, const map<Key, T>& rhs) 
	{
		if (lhs.size() != rhs.size())
		return false;
		typename map<Key, T>::const_iterator it1 = lhs.begin();
		typename map<Key, T>::const_iterator it2 = rhs.begin();

		while (it1 != lhs.end() && it2 != rhs.end()) {
		if (*it1 != *it2)
			return false;
		it1++;
		it2++;
		}
		return (it1 == lhs.end()) && (it2 == rhs.end());
	};

	template <class Key, class T>
	bool operator!=(const map<Key, T>& lhs, const map<Key, T>& rhs) { return !(lhs == rhs); };

	template <class Key, class T>
	bool operator<(const map<Key, T>& lhs, const map<Key, T>& rhs)
	{
		typename map<Key, T>::const_iterator it1 = lhs.begin();
		typename map<Key, T>::const_iterator it2 = rhs.begin();

		while (it1 != lhs.end() && it2 != rhs.end()) {
		if (*it1 < *it2)
			return true;
		if (*it2 < *it1)
			return false;
		it1++;
		it2++;
		}
		return (it1 == lhs.end()) && (it2 != rhs.end());
	};

	template <class Key, class T>
	bool operator<=(const map<Key, T>& lhs, const map<Key, T>& rhs) { return !(rhs < lhs); };

	template <class Key, class T>
	bool operator>(const map<Key, T>& lhs, const map<Key, T>& rhs) { return rhs < lhs; };

	template <class Key, class T>
	bool operator>=(const map<Key, T>& lhs, const map<Key, T>& rhs) { return !(lhs < rhs); };

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	};
}

#endif