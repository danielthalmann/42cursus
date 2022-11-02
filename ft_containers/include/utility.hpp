#ifndef VECTOR_HPP
#define VECTOR_HPP

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
      
	}

}

#endif
