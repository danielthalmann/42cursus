#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{

	template<typename Iterator>
	class reverse_iterator
		: public iterator<	typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference>
	{
	
	protected:
		Iterator current;

		typedef iterator_traits<Iterator>		traits_type;

	public:
		typedef Iterator								iterator_type;
		typedef typename traits_type::difference_type	difference_type;
		typedef typename traits_type::pointer			pointer;
		typedef typename traits_type::reference			reference;

		reverse_iterator() : current() { }
		reverse_iterator(iterator_type i) : current(i) { }
		reverse_iterator(const reverse_iterator& i) : current(i.current) { }
		template<typename _Iter>
		reverse_iterator(const reverse_iterator<_Iter>& i) : current(i.base()) { }

		iterator_type base() const { return current; }

		reference operator*() const	{	Iterator tmp = current;	return *--tmp; }

		pointer	operator->() const { return &(operator*()); }

		reverse_iterator& operator++() {	--current; return *this; }

		reverse_iterator operator++(int) {	reverse_iterator tmp = *this; --current; return tmp; }

		/**
		 *  @return  @c *this
		 *
		 *  Increments the underlying iterator.
		 */
		_GLIBCXX17_CONSTEXPR reverse_iterator&
		operator--()
		{
		++current;
		return *this;
		}

		/**
		 *  @return  A reverse_iterator with the previous value of @c *this
		 *
		 *  Increments the underlying iterator.
		 */
		_GLIBCXX17_CONSTEXPR reverse_iterator
		operator--(int)
		{
		reverse_iterator __tmp = *this;
		++current;
		return __tmp;
		}

		/**
		 *  @return  A reverse_iterator that refers to @c current - @a __n
		 *
		 *  The underlying iterator must be a Random Access Iterator.
		 */
		_GLIBCXX17_CONSTEXPR reverse_iterator
		operator+(difference_type __n) const
		{ return reverse_iterator(current - __n); }

		/**
		 *  @return  *this
		 *
		 *  Moves the underlying iterator backwards @a __n steps.
		 *  The underlying iterator must be a Random Access Iterator.
		 */
		_GLIBCXX17_CONSTEXPR reverse_iterator&
		operator+=(difference_type __n)
		{
		current -= __n;
		return *this;
		}

		/**
		 *  @return  A reverse_iterator that refers to @c current - @a __n
		 *
		 *  The underlying iterator must be a Random Access Iterator.
		 */
		_GLIBCXX17_CONSTEXPR reverse_iterator
		operator-(difference_type __n) const
		{ return reverse_iterator(current + __n); }

		/**
		 *  @return  *this
		 *
		 *  Moves the underlying iterator forwards @a __n steps.
		 *  The underlying iterator must be a Random Access Iterator.
		 */
		_GLIBCXX17_CONSTEXPR reverse_iterator&
		operator-=(difference_type __n)
		{
		current += __n;
		return *this;
		}

		/**
		 *  @return  The value at @c current - @a __n - 1
		 *
		 *  The underlying iterator must be a Random Access Iterator.
		 */
		_GLIBCXX17_CONSTEXPR reference
		operator[](difference_type __n) const
		{ return *(*this + __n); }
		};

	//@{
	/**
	 *  @param  __x  A %reverse_iterator.
	 *  @param  __y  A %reverse_iterator.
	 *  @return  A simple bool.
	 *
	 *  Reverse iterators forward many operations to their underlying base()
	 *  iterators.  Others are implemented in terms of one another.
	 *
	 */
	template<typename _Iterator>
		inline _GLIBCXX17_CONSTEXPR bool
		operator==(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return __x.base() == __y.base(); }

	template<typename _Iterator>
		inline _GLIBCXX17_CONSTEXPR bool
		operator<(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return __y.base() < __x.base(); }

	template<typename _Iterator>
		inline _GLIBCXX17_CONSTEXPR bool
		operator!=(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return !(__x == __y); }

	template<typename _Iterator>
		inline _GLIBCXX17_CONSTEXPR bool
		operator>(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return __y < __x; }

	template<typename _Iterator>
		inline _GLIBCXX17_CONSTEXPR bool
		operator<=(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return !(__y < __x); }

	template<typename _Iterator>
		inline _GLIBCXX17_CONSTEXPR bool
		operator>=(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return !(__x < __y); }

	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// DR 280. Comparison of reverse_iterator to const reverse_iterator.
	template<typename _IteratorL, typename _IteratorR>
		inline _GLIBCXX17_CONSTEXPR bool
		operator==(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return __x.base() == __y.base(); }

	template<typename _IteratorL, typename _IteratorR>
		inline _GLIBCXX17_CONSTEXPR bool
		operator<(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return __y.base() < __x.base(); }

	template<typename _IteratorL, typename _IteratorR>
		inline _GLIBCXX17_CONSTEXPR bool
		operator!=(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return !(__x == __y); }

	template<typename _IteratorL, typename _IteratorR>
		inline _GLIBCXX17_CONSTEXPR bool
		operator>(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return __y < __x; }

	template<typename _IteratorL, typename _IteratorR>
		inline _GLIBCXX17_CONSTEXPR bool
		operator<=(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return !(__y < __x); }

	template<typename _IteratorL, typename _IteratorR>
		inline _GLIBCXX17_CONSTEXPR bool
		operator>=(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return !(__x < __y); }
	//@}

	template<typename _Iterator>
		inline typename reverse_iterator<_Iterator>::difference_type
		operator-(const reverse_iterator<_Iterator>& __x,
			const reverse_iterator<_Iterator>& __y)
		{ return __y.base() - __x.base(); }

	template<typename _IteratorL, typename _IteratorR>
		inline typename reverse_iterator<_IteratorL>::difference_type
		operator-(const reverse_iterator<_IteratorL>& __x,
			const reverse_iterator<_IteratorR>& __y)
		{ return __y.base() - __x.base(); }


}

#endif