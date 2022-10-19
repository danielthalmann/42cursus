#include <iostream>
#include <string>
#include <deque>
#ifdef COMPILE_LIB_STD
	#include <vector>
	namespace ft = std;
#else
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))


int main( int argc, char **argv ) {

	if (argc == 1)
	{
		
	}

    #ifdef COMPILE_LIB_STD
        std::cerr << "Lib std" << std::endl;
    #else
        std::cerr << "Lib ft" << std::endl;
    #endif

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::vector<Buffer> vector_buffer;

    // vector_int.push_back(1);
    // vector_int.resize(5, 42);
// 
    // std::cout << "front: " << vector_int.front() << std::endl;
    // std::cout << "back: " << vector_int.back() << std::endl;


	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}

	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	return (0);
}
