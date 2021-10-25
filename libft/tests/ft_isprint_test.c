#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_isprint_test(int c);

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
	
	s = ft_fake_printable(5);
	i = -1;
	while (s[++i])
		ft_isprint_test(s[i]);
	free(s);

	ft_isprint_test(190);
	ft_isprint_test('\n');
}

void ft_isprint_test(int c)
{
	int r;
	int e;
	r = ft_isprint(c);
	e = isprint(c);
	printf("string [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\n", c, e ? 1 : 0, r ? 1 : 0);
	assert(r ? 1 : 0 == e ? 1 : 0 );
}
