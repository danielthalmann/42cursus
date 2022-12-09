#include <iostream>
#include <map>
#include <string>
#include <type_traits>

template <typename T> 
T get() { /* generic implementation emit exception */  return T(); }

template <> 
std::string get<std::string>()   
{ /* specific for T = std::string */ 
	std::cout << "string";
	return std::string("test");
}

template <> 
int get<int>()   
{ /* specific for T = int */ 
	std::cout << "int";
	return 5;
}


void  test ()
{

    get<std::string>();
    get<int>();

}

int main( void ) 
{
	test();

	return (0);
}
