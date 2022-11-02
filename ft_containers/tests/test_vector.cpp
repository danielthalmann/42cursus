#include <iostream>
#include <vector>
#ifdef COMPILE_LIB_STD
	namespace ft = std;
#else
	#include <vector.hpp>
#endif
#include <set>
#include <map>
#include <utility>
#include "test_vector.hpp"

#define TEST_CASE(_TITLE, _CMD, _TEST, _MSG) std::cout << "TEST : " << _TITLE << std::endl; _CMD ; if (_TEST) { std::cout << "\x1b[31m" << "ERROR : " << "\x1b[0m" << _MSG << std::endl; /* return ;*/ }

void test_constructor( void )
{

	// construct 

	TEST_CASE( 
		"vector<int> v",
		ft::vector<int> v,
		(v.size() != 0), 
		"Size after initial constructor is not correct, size : " << v.size()
		)

	TEST_CASE( 
		"vector<int> v2(5, 42)",
		ft::vector<int> v2(5, 42),
		(v2.size() != 5) || (v2.back() != 42 || v2.front() != 42), 
		"Size after initial constructor is not correct, size : " << v2.size()
		)

	TEST_CASE( 
		"vector<int> v3(v2) (construct by copy)",
		ft::vector<int> v3(v2),
		v3.size() != 5 || v2.back() != 42 || v2.front() != 42, 
		"Size after copy constructor is not correct"
		)
}

void test_assign( void )
{

	TEST_CASE(
		"assign(size_type n, const_reference v)", 
		ft::vector<int> v; v.assign(3, 42),
		v.size() != 3, 
		"Size after assign is not correct, value : " << v.size()
		)
	
	std::vector<int> in;
	in.push_back(3);

	TEST_CASE(
		"assign(InputIterator first, InputIterator last)", 
		ft::vector<int> v2; v2.assign(in.begin(), in.end()),
		v2.size() != 1 || v2.front() != 3|| v2.back() != 3, 
		"Size after assign is not correct, value : " << v2.size()
		)

}
void test_element_access ( void )
{
	ft::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);

	TEST_CASE(
		"reference at(size_type n)", 
		,
		v.at(1) != 2 || v.at(2) != 4, 
		"invalid value"
		)

	TEST_CASE(
		"reference operator[](size_type n)", 
		,
		v[1] != 2 || v[2] != 4, 
		"invalid value"
		)

	TEST_CASE(
		"reference front()", 
		,
		v.front() != 1, 
		"invalid value"
		)

	TEST_CASE(
		"reference back()", 
		,
		v.back() != 8, 
		"invalid value"
		)

	TEST_CASE(
		"pointer data()", 
		,
		v.data()[3] != 8, 
		"invalid value"
		)

}


void test_iterrator (void)
{
	ft::vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);

	TEST_CASE(
		"iterator begin()", 
		,
		*(v.begin()) != 1, 
		"invalid value"
		)

	TEST_CASE(
		"iterator end()", 
		ft::vector<int>::iterator iter; iter = v.end(),
		*(--iter) != 8, 
		"invalid value"
		)

	TEST_CASE(
		"iterator rbegin()", 
		,
		*(v.rbegin()) != 8, 
		"invalid value"
		)

	TEST_CASE(
		"iterator rend()", 
		ft::vector<int>::reverse_iterator reviter; reviter = v.rend(),
		*(--reviter) != 1, 
		"invalid value " 
		)

}

void test_capacity( void )
{

	TEST_CASE(
		"bool empty()", 
		ft::vector<int> v1(5, 5); ft::vector<int> v1empty,
		v1.empty() == true || v1empty.empty() == false, 
		"invalid capacity" 
		)

	TEST_CASE(
		"size_type size()", 
		ft::vector<int> v2(5, 5),
		v2.size() != 5, 
		"invalid size " 
		)

	TEST_CASE(
		"size_type max_size()", 
		ft::vector<int> v3,
		v3.max_size() == 0, 
		"invalid max_size " << v3.max_size()
		)

	TEST_CASE(
		"void reserve( size_type n )", 
		ft::vector<int> v4; v4.reserve(44),
		v4.size() != 0 || v4.capacity() != 44, 
		"invalid reserve" 
		)

	TEST_CASE(
		"size_type capacity()", 
		ft::vector<int> v5; v5.reserve(44),
		v5.size() != 0 || v5.capacity() != 44, 
		"invalid reserve" 
		)
}

void test_modifier()
{
	ft::vector<int> v;
	
	v.push_back(1);
	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;
	v.push_back(2);
	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;
	v.push_back(4);
	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;
	v.push_back(8);

	ft::vector<int> vs;
	
	vs.push_back(16);
	vs.push_back(32);
	vs.push_back(64);
	vs.push_back(128);

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"void clear()", 
		ft::vector<int> v1(5, 5); v1.clear(),
		v1.empty() != true || v1.size() != 0, 
		"invalid capacity" 
		)

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"iterator insert( const_iterator pos, const T& value ) ", 
		ft::vector<int>::iterator itr = v.begin(); v.insert(itr, 99),
		v[0] != 99 || v[1] != 1 || v.size() != 5, 
		"invalid size " << v.size() << " or value " << v[0]
		)

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"iterator erase (iterator pos) ",
		ft::vector<int> v_(v); ft::vector<int>::iterator itr2 = v_.begin(); v_.erase(itr2),
		v_[0] != 1 || v_[1] != 2 || v_.size() != 4, 
		"invalid capacity size : " << v_.size() << " last : "<< v_.back() << " v_[0] : "<< v_[0]
		)

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"iterator erase (iterator first, iterator last ) ", 
		ft::vector<int>::iterator b = v.begin(); ft::vector<int>::iterator e = v.end(); e = e - 2; v.erase(b, e),
		v[0] == 1 || v.size() != 2, 
		"invalid value " << v[0] << " or size " << v.size()
		)

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"void push_back(const value_type& v)  " << v.size(), 
		v.push_back(11),
		v.size() != 3 || v[v.size() - 1] != 11, 
		"invalid" << v.size()
		)

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"void pop_back() size : " << v.size() << " last : "<< v.back(), 
		v.pop_back(),
		v[v.size() - 1] != 8, 
		"invalid " << v[v.size() - 1] << " " << v.size()
		)
	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"void resize(size_type n, value_type v = value_type()) " << v.size() , 
		v.resize(10, 42),
		v[v.size() - 1] != 42 || v.size() != 10, 
		"invalid size " << v.size() << " or value " << v[v.size() - 1]
		)

	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"void resize(size_type n, value_type v = value_type()) " << v.size() , 
		v.resize(1),
		v.size() != 1, 
		"invalid" << v.size() << "t" << v[v.size() - 1]
		)
	
	std::cout << "       capacity " << v.capacity() << " size " << v.size() << std::endl;

	TEST_CASE(
		"void swap( vector<T, allocator>& other )", 
		v.swap(vs),
		v[v.size() - 1] != 128 || v.size() != 4, 
		"invalid size " << v.size() << " or value " << v[v.size() - 1]
		)

}