#include <stdio.h>
#include "vector.hpp"
#include <vector>


int main(int argc, char* argv[])
{
    allocator<int> i;
    (void) i;
    (void) argc;
    (void) argv;

    ft::vector<int> v;
   

    printf("Hello world\n");
    return 0;
}
