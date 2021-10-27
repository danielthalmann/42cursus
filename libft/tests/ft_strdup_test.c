#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strdup_test(char *s, int len);

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

	i = 0;
	while (i < 10)
	{
		s = ft_fake_alpha(i + 5);
		s[i + 3] = 0;
		ft_strdup_test(s, i + 4);
		free(s);
		i++;
	}

}

void ft_strdup_test(char *s, int len)
{
	char	*e;
	char	*r;

	e = strdup(s);
	r = ft_strdup(s);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, e, r);

	assert(strlen(r) == strlen(e));
	assert(memcmp(r, e, len) == 0);

	free(e);
	free(r);
}
