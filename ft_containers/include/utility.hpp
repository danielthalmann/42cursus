#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "algorithm.hpp"

namespace ft
{

	template< class T1, class T2 > class pair
	{
	public:

		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() { }
		pair(const T1& a, const T2& b) : first(a), second(b) { }
		template<typename U1, typename U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }
		
		pair &operator=(const pair other) { first = other.first; second = other.second; return *this; }

		void swap( pair& other )
		{
			ft::swap(this->first, other.first);
			ft::swap(this->second, other.second);
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template< class T1, class T2 >
	void swap( pair<T1,T2>& lhs, pair<T1,T2>& rhs )
	{
		lhs.swap(rhs);
	}

	template< class T1, class T2 >
	pair<T1,T2> make_pair(T1 a, T2 b)
	{
		return pair<T1, T2>(a, b);
	}

}

#endif
