#include <iostream>
#ifdef COMPILE_LIB_STD
	#include <vector>
	namespace ft = std;
#else
	#include <vector.hpp>
#endif
#include <set>
#include "test_vector.hpp"

#define TEST_CASE(_TITLE, _CMD, _TEST, _MSG) std::cout << _TITLE << std::endl; _CMD ; if (_TEST) { std::cout << _MSG << std::endl; return ; }


void test_constructor( )
{

	// construct 
	ft::vector<int> v;
	
	TEST_CASE( 
		"construct",
		ft::vector<int> v2(5, 42),
		v2.size() != 5, 
		"Size after initial constructor is not correct, value : " << v2.size()
		)

	TEST_CASE( 
		"verify data",
		,
		v2.back() != 42 || v2.front() != 42, 
		"Data after initial constructor is not correct"
		)

	TEST_CASE( 
		"construct by copy",
		ft::vector<int> v3(v2),
		v3.size() != 5, 
		"Size after copy constructor is not correct"
		)
	TEST_CASE( 
		"verify data",
		,
		v3.size() != 5, 
		"Data after constructor is not correct"
		)

}

void test_assign( )
{
	
	

	TEST_CASE(
		"assign", 
		ft::vector<int> v; v.assign(3, 42),
		v.size() != 3, 
		"Size after assign is not correct, value : " << v.size()
		)

	ft::vector<int> in;
	in.push_back(3);

	//v.assign(in.begin(), in.end());
	//TEST_CASE(v.size() != 1, "Size after assign is not correct\n")

}

