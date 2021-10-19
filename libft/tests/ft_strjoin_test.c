#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strjoin_test(char *s1, char *s2);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{

	char	*s1;
	char	*s2;
	int		i;
	(void) argc;
	(void) argv;

	i = -1;
	while (i < 10)
	{
		s1 = ft_fake_printable(i + 5);
		s2 = ft_fake_printable(i + 2);
		ft_strjoin_test(s1, s2);
		free(s1);
		free(s2);
		i++;
	}

}

void ft_strjoin_test(char *s1, char *s2)
{
	char	*r;

	r = ft_strjoin(s1, s2);
	printf("string [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tstring [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s1, s2, r);
	//	assert(strcmp(r, e) == 0);
	free(r);
}
