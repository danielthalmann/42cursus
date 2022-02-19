#include <stdio.h>
#include <unistd.h>
int main()
{
	int p = getpid();
	printf("%d : hello", p);
}
