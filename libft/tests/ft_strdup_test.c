#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strdup_test(char *s);

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

	i = -1;
	while (i < 10)
	{
		s = ft_fake_alpha(i + 5);
		ft_strdup_test(s);
		free(s);
		i++;
	}

}

void ft_strdup_test(char *s)
{
	char	*e;
	char	*r;

	e = strdup(s);
	r = ft_strdup(s);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, e, r);

	assert(strcmp(r, e) == 0);

	free(e);
	free(r);
}
