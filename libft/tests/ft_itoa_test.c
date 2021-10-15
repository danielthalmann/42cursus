#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_itoa_test(int i, char *e);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{
	char	*s;
	int		i;

	ft_itoa_test(54321, "54321");
	ft_itoa_test(-54321, "-54321");
}

void ft_itoa_test(int i, char *e)
{
	char *r;
	r = ft_itoa(i);
	printf("integer [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", i, e, r );
	assert(strcmp(r, e) == 0);
}
