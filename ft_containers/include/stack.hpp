#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"
#include <cstddef>

namespace ft
{
	template< class T, class Container = ft::vector< T > >
	class stack
	{
	public:
    typedef Container                                container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;

	protected:
		container_type c;


	public:
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
        virtual ~stack() { };

        stack& operator=( const stack& other ) { c = other.c; }

		/**
		 * Element access 
		 */

		reference top() { return c.back(); }
		const_reference top() const { return c.back(); }

		/**
		 * Capacity 
		 */

		bool empty() const { return c.empty(); }
		size_type size() const { return c.size(); }

		/**
		 * Modifiers
		 */

		void push(const value_type &value) { c.push_back(value); }
		void pop() { c.pop_back(); }
        

	};


	template< class T, class Container >
	bool operator==(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
	{
		return (lhs.c == rhs.c);
	}


	template< class T, class Container >
	bool operator!=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
	{
		return (!(lhs == rhs));
	}


	template< class T, class Container >
	bool operator<(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
	{
		return (lhs.c < rhs.c);
	}


	template< class T, class Container >
	bool operator<=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
	{
		return (!(rhs < lhs));
	}


	template< class T, class Container >
	bool operator>(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
	{
		return (rhs < lhs);
	}


	template< class T, class Container >
	bool operator>=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
	{
		return !(lhs < rhs);
	}

}

#endif