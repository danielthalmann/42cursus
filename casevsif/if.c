
#include <stdio.h>

void function1(void)
{
	printf("function1\n");
}

void function2(void)
{
	printf("function2\n");
}

void function3(void)
{
	printf("function3\n");
}

int main(void)
{
	int value = 2;

	if (value == 1)
		function1();
	else if (value == 2)
		function2();
	else if (value == 3)
 		function3();
	return (0);	
}