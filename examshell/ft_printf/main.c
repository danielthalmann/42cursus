
#include <stdio.h>

#include "ft_printf.c"

int main(int argc, char **argv)
{
	int v;

	v = ft_printf("string %s\n", "salut Daniel");
	printf("%d\n", v);
	v = ft_printf("char %c\n", 'c');
	printf("%d\n", v);
 	v = ft_printf("int %d\n", 1024);
	printf("%d\n", v);
 	v = ft_printf("int %d\n", -2048);
	printf("%d\n", v);

}
