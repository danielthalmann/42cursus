#include <iostream>
#include <map>
#include <string>
#include <type_traits>

/*
  /// is_same
  template<typename, typename>
    struct is_same
    : public false_type { };

  template<typename _Tp>
    struct is_same<_Tp, _Tp>
    : public true_type { };
*/

template <typename T>
T *get()
{
	if(std::is_same<T, std::string>::value)
	{
    	std::cout << "string";
	}
	if(std::is_same<T, int>::value){
    	std::cout << "int";
	}
	return new T;

};

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
