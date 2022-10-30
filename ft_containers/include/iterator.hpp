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
		Iterator _cursor;

	private:
		typedef iterator_traits< Iterator > traits_type;
	
	public:
		typedef Iterator iterator_type;
		typedef typename traits_type::iterator_category  iterator_category;
		typedef typename traits_type::value_type         value_type;
		typedef typename traits_type::difference_type    difference_type;
		typedef typename traits_type::pointer            pointer;
		typedef typename traits_type::reference          reference;
		typedef random_access_iterator      iter;

	public:

		random_access_iterator() : _cursor(Iterator()) {}
		random_access_iterator(const Iterator &start) : _cursor(start) {}
		iter& operator++() { _cursor++; return *this; }
		iter operator++(int) {iter retval = *this; ++(*this); return retval; }
		iter& operator--() { _cursor--; return *this; }
		iter operator--(int) {iter retval = *this; --(*this); return retval; }
		iter operator-(int value) const { return iter(_cursor - value); }
		iter operator+(int value) const { return iter(_cursor + value); }
		bool operator==(iter other) const {return _cursor == other._cursor;}
		bool operator!=(iter other) const {return !(*this == other);}
		bool operator<(iter other) const {return (_cursor < other._cursor);}
		reference operator*() const {return *_cursor;}
		const Iterator& base() const { return _cursor; }
	};
	
	template< class Iterator >
	typename random_access_iterator< Iterator >::difference_type
	operator-(const random_access_iterator< Iterator > &lhs,
			  const random_access_iterator< Iterator > &rhs)
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