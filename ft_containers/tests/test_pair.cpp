#include <iostream>
#include <vector>
#ifdef COMPILE_LIB_STD
	namespace ft = std;
#else
	#include <utility.hpp>
#endif
#include <set>
#include <map>
#include <utility>
#include <stack>
#include "test_vector.hpp"

#define TEST_CASE(_TITLE, _CMD, _TEST, _MSG)  std::cout << "TEST : " << _TITLE << std::endl; _CMD ; if (_TEST) { std::cout << "\x1b[31m" << "ERROR : " << "\x1b[0m" << _MSG << std::endl; /* return ;*/ }

void test_constructor( void )
{

	// construct 
	ft::pair<int, char> v(11, 'd');

	TEST_CASE( 
		"ft::pair<int, char>",
		,
		(v.second != 'd' || v.first != 11) ,
		"constructor failed" 
		)

}

int main( void ) 
{
	test_constructor();

	return (0);
}
