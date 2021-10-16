#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_memset_test(char c, int size);

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
	(void) argc;
	(void) argv;

	i = 5;
	while (i < 20)
	{
		s = ft_fake_printable(1);
		ft_memset_test(*s, i);
		free(s);
		i++;
	}

}

void ft_memset_test(char c, int size)
{
	char	*e;
	char	*r;

	e = calloc(size + 1, 1);
	r = calloc(size + 1, 1);
 
	e = memset(e, c, size);
	r = ft_memset(r, c, size);
	printf("Char [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", c, e, r);

	assert(strcmp(r, e) == 0);

	free(e);
	free(r);
}
