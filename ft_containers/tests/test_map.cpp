#include <iostream>
#include "map.hpp"
#include <memory>
#include <map>

#define TEST_CASE(_TITLE, _CMD, _TEST, _MSG)  std::cout << "TEST : " << _TITLE << std::endl; _CMD ; if (_TEST) { std::cout << "\x1b[31m" << "ERROR : " << "\x1b[0m" << _MSG << std::endl; /* return ;*/ }
 

void printint(int &i, size_t level)
{
    std::cout << level << ":" << i << "\t" ;
}

void insert(int v, ft::Tree <int, std::allocator<int> > &arbre)
{
    arbre.insert(v);
    arbre.infix(&printint); std::cout << " " << arbre.size() << '\n';
}

void  test ( )
{

	ft::map<int, int> m;

	m[5] = 1;

	std::cout << m[5] << std::endl;
    

}

int main( void ) 
{
	test();

	return (0);
}
