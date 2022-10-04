#include <stdio.h>
#include "allocator.hpp"


int main(int argc, char* argv[])
{
    allocator<int> i;
    (void) i;
    (void) argc;
    (void) argv;

    printf("Hello world\n");
    return 0;
}
