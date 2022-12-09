#include <iostream>
#include <map>
#include <string>
#include <type_traits>


template<typename>
struct is_json_type_helper
: public std::false_type 
{ };

template<>
struct is_json_type_helper<std::string>
: public std::true_type
{ };

template<typename T>
struct is_json_type
: public is_json_type_helper< T >
{ };


template <typename T>
int get(typename std::enable_if< is_json_type<T>::value, int>::type = 0 )
{
    std::cout << "string";
    return 0;
};


template <typename T>
int get(typename std::enable_if< !is_json_type<T>::value, int>::type = 0 )
{
    std::cout << "unknow";
    return 0;
};


void  test ( )
{

    get<std::string>();
    get<int>();

}

int main( void ) 
{
	test();

	return (0);
}
