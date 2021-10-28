#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_memmove_test(char *s, int size);

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
		ft_memmove_test(s, i + 6);
		free(s);
		i++;
	}

	i = 0;
	while (i < 10)
	{
		s = ft_fake_alpha(i + 5);
		ft_memmove_test(s, i + 6);
		free(s);
		i++;
	}

}

void ft_memmove_test(char *s, int size)
{
	char	*e;
	char	*r;
	int		d;

	d = 3;
	e = malloc(size + d);
	strcpy(e, s);
	r = malloc(size + d);
	strcpy(r, s);

	e = memmove(e, e + d, size);
	r = ft_memmove(r, r + d, size);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, e, r);

	assert(strcmp(r, e) == 0);

	free(e);
	free(r);
}

void ft_memmove_revert_test(char *s, int size)
{
	char	*e;
	char	*r;
	int		d;

	d = 3;
	e = malloc(size + d);
	strcpy(e, s);
	r = malloc(size + d);
	strcpy(r, s);

	e = memmove(e + d, e, size);
	r = ft_memmove(r + d, s, size);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, e, r);

	assert(strcmp(r, e) == 0);

	free(e);
	free(r);
}

