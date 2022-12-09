
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

	switch (value)
	{
	case 1:
		function1();
		break;
	case 2:
		function2();
		break;
	case 3:
		function3();
		break;
	}
	return (0);	
}