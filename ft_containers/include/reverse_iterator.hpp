#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{

	template < typename Iterator >
	class reverse_iterator
	{
	
	protected:
		Iterator current;

		typedef ft::iterator_traits<Iterator>	traits_type;

	public:
		typedef Iterator								iterator_type;
		typedef typename traits_type::iterator_category	iterator_category;
		typedef typename traits_type::value_type		value_type;
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
		reverse_iterator& operator--()	{	++current; return *this;	}
		reverse_iterator operator--(int) {	reverse_iterator tmp = *this; ++current; return tmp; }
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); }
		reverse_iterator& operator+=(difference_type n) {	current -= n; return *this;	}
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); }
		reverse_iterator& operator-=(difference_type n) {	current += n; return *this;	}
		reference operator[](difference_type n) const	{ return *(*this + n); }

	};

	template<typename _Iterator>
	bool operator==(const reverse_iterator<_Iterator>& x,	const reverse_iterator<_Iterator>& y)
	{ return x.base() == y.base(); }

	template<typename _Iterator>
	bool operator<(const reverse_iterator<_Iterator>& x,	const reverse_iterator<_Iterator>& y)
	{ return y.base() < x.base(); }

	template<typename _Iterator>
	bool operator!=(const reverse_iterator<_Iterator>& x,	const reverse_iterator<_Iterator>& y)
	{ return !(x == y); }

	template<typename _Iterator>
	bool operator>(const reverse_iterator<_Iterator>& x,	const reverse_iterator<_Iterator>& y)
	{ return y < x; }

	template<typename _Iterator>
	bool operator<=(const reverse_iterator<_Iterator>& x,	const reverse_iterator<_Iterator>& y)
	{ return !(y < x); }

	template<typename _Iterator>
	bool operator>=(const reverse_iterator<_Iterator>& x,	const reverse_iterator<_Iterator>& y)
	{ return !(x < y); }

	template<typename _IteratorL, typename _IteratorR>
	bool operator==(const reverse_iterator<_IteratorL>& x, const reverse_iterator<_IteratorR>& y)
	{ return x.base() == y.base(); }

	template<typename _IteratorL, typename _IteratorR>
	bool operator<(const reverse_iterator<_IteratorL>& x,	const reverse_iterator<_IteratorR>& y)
	{ return y.base() < x.base(); }

	template<typename _IteratorL, typename _IteratorR>
	bool operator!=(const reverse_iterator<_IteratorL>& x,	const reverse_iterator<_IteratorR>& y)
	{ return !(x == y); }

	template<typename _IteratorL, typename _IteratorR>
	bool operator>(const reverse_iterator<_IteratorL>& x,	const reverse_iterator<_IteratorR>& y)
	{ return y < x; }

	template<typename _IteratorL, typename _IteratorR>
	bool operator<=(const reverse_iterator<_IteratorL>& x,	const reverse_iterator<_IteratorR>& y)
	{ return !(y < x); }

	template<typename _IteratorL, typename _IteratorR>
	bool operator>=(const reverse_iterator<_IteratorL>& x,	const reverse_iterator<_IteratorR>& y)
	{ return !(x < y); }

	template<typename _Iterator>
		inline typename reverse_iterator<_Iterator>::difference_type
		operator-(const reverse_iterator<_Iterator>& x,
			const reverse_iterator<_Iterator>& y)
	{ return y.base() - x.base(); }

	template<typename _IteratorL, typename _IteratorR>
		inline typename reverse_iterator<_IteratorL>::difference_type
		operator-(const reverse_iterator<_IteratorL>& x,
			const reverse_iterator<_IteratorR>& y)
	{ return y.base() - x.base(); }

}

#endif