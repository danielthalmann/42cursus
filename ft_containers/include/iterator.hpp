#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	typedef long long ptrdiff_t;

	///  Marking input iterators.
	struct input_iterator_tag { };

	///  Marking output iterators.
	struct output_iterator_tag { };

	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag { };

	/// Bidirectional iterators support a superset of forward iterator
	/// operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag { };

	/// Random-access iterators support a superset of bidirectional
	/// iterator operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };


	template<typename Category, typename Tp, typename Distance = ptrdiff_t,
			typename Pointer = Tp*, typename Reference = Tp&>
	struct iterator
	{
		typedef Category  iterator_category;
		typedef Tp        value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

	template<typename Iterator>
    struct iterator_traits
    { 
		typedef typename Iterator::iterator_category  iterator_category;
		typedef typename Iterator::value_type         value_type;
		typedef typename Iterator::difference_type    difference_type;
		typedef typename Iterator::pointer            pointer;
		typedef typename Iterator::reference          reference;
	};

	/// Partial specialization for pointer types.
	template<typename T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag  iterator_category;
		typedef T                           value_type;
		typedef ptrdiff_t                   difference_type;
		typedef T*                          pointer;
		typedef T&                          reference;
	};

	/// Partial specialization for const pointer types.
	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag  iterator_category;
		typedef T                           value_type;
		typedef ptrdiff_t                   difference_type;
		typedef const T*                    pointer;
		typedef const T&                    reference;
	};
	

	template < typename Iterator >
	class random_access_iterator 
	{
    protected:
		Iterator current;

	private:
		typedef iterator_traits< Iterator > traits_type;
	
	public:
		typedef Iterator									iterator_type;
		typedef typename traits_type::iterator_category		iterator_category;
		typedef typename traits_type::value_type			value_type;
		typedef typename traits_type::difference_type		difference_type;
		typedef typename traits_type::pointer				pointer;
		typedef typename traits_type::reference				reference;

	public:

		random_access_iterator() : current(Iterator()) {}
		random_access_iterator(const Iterator &start) : current(start) {}
		
		template< typename Iter >
		random_access_iterator(const random_access_iterator< Iter > &rev_it) : current(rev_it.base()) {}

		const Iterator& base() const { return current; }

		reference operator*() const {return *current;}
		pointer	operator->() const { return &(operator*()); }
		random_access_iterator& operator++() { current++; return *this; }
		random_access_iterator operator++(int) {random_access_iterator retval = *this; ++(*this); return retval; }
		random_access_iterator& operator--() { current--; return *this; }
		random_access_iterator operator--(int) {random_access_iterator retval = *this; --(*this); return retval; }
		random_access_iterator operator+(difference_type n) const { return random_access_iterator(current + n); }
		random_access_iterator& operator+=(difference_type n) {	current += n; return *this;	}
		random_access_iterator operator-(difference_type n) const { return random_access_iterator(current - n); }
		random_access_iterator& operator-=(difference_type n) {	current -= n; return *this;	}
		reference operator[](difference_type n) const	{ return *(*this + n); }
		bool operator==(random_access_iterator other) const {return current == other.current;}
		bool operator!=(random_access_iterator other) const {return !(*this == other);}
		bool operator<(random_access_iterator other) const {return (current < other.current);}
	};
	
	template< typename Iterator >
	bool operator>(const random_access_iterator< Iterator > &lhs,
					const random_access_iterator< Iterator > &rhs)
	{
		return (rhs < lhs);
	}
	
	template< typename Iterator >
	bool operator>=(const random_access_iterator< Iterator > &lhs,
					const random_access_iterator< Iterator > &rhs)
	{
		return !(lhs < rhs);
	}
	
	template< typename Iterator >
	bool operator<=(const random_access_iterator< Iterator > &lhs,
					const random_access_iterator< Iterator > &rhs)
	{
		return !(operator>(lhs, rhs));
	}

	template< class Iterator >
	typename random_access_iterator< Iterator >::difference_type
	operator-(const random_access_iterator< Iterator > &lhs,
			  const random_access_iterator< Iterator > &rhs)
	{
		return (lhs.base() - rhs.base());
	}
		
	template< class IteratorL, class IteratorR >
	typename random_access_iterator< IteratorL >::difference_type
	operator-(const random_access_iterator< IteratorL > &lhs,
						   const random_access_iterator< IteratorR > &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template< class Iterator >
	typename random_access_iterator< Iterator >::difference_type
	operator+(const random_access_iterator< Iterator > &lhs,
			  const random_access_iterator< Iterator > &rhs)
	{
		return (lhs.base() + rhs.base());
	}
		
	template< class Iterator >
	random_access_iterator< Iterator >
	operator+(const int &lhs,
			  const random_access_iterator< Iterator > &rhs)
	{
		return random_access_iterator< Iterator >(rhs.base() + lhs);
	}

	template< typename IteratorL, typename IteratorR >
	inline bool operator==(const random_access_iterator< IteratorL > &lhs,
						   const random_access_iterator< IteratorR > &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template< typename Iterator >
	bool operator!=(const random_access_iterator< Iterator > &lhs,
					const random_access_iterator< Iterator > &rhs)
	{
		return (!(lhs == rhs));
	}

	template< typename IteratorL, typename IteratorR >
	bool operator!=(const random_access_iterator< IteratorL > &lhs,
					const random_access_iterator< IteratorR > &rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Iterator>
	typename iterator_traits<Iterator>::iterator_category _iterator_category(const Iterator&) 
	{ 
		return typename iterator_traits<Iterator>::iterator_category(); 
	}

	template<typename RandomAccessIterator>
	typename iterator_traits<RandomAccessIterator>::difference_type _distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
	{
		return last - first;
	}

	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type _distance(InputIterator first, InputIterator last, input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	}

	template < typename InputIterator >
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
		// return _distance(first, last, _iterator_category(first));
	}

}

#endif