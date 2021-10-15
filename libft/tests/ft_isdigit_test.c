#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_isdigit_test(char c);

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

	s = ft_fake_printable(5);
	i = -1;
	while (s[++i])
		ft_isdigit_test(s[i]);
	free(s);

	s = ft_fake_digit(5);
	i = -1;
	while (s[++i])
		ft_isdigit_test(s[i]);
	free(s);
}

void ft_isdigit_test(char c)
{
	int r;
	int e;
	r = ft_isdigit(c);
	e = isdigit(c);
	printf("string [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\n", c, e ? 1 : 0, r ? 1 : 0);
	assert(r ? 1 : 0 == e ? 1 : 0 );
}
