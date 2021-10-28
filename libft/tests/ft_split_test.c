#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_split_test(char *s, int sep, char **e);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	char *a[1] = { 0 };
	char *b[2] = { "test", 0 };
	char *c[5] = { "at", "te", "st", "te", 0 };
	char *d[3] = { "bon", "jour", 0 };
	

	ft_split_test("|||", '|', a);
	ft_split_test("|test||", '|', b);
	ft_split_test("at|te|st|te", '|', c);
	ft_split_test("bon||jour|", '|', d);
	ft_split_test("", '|', a);

}

void ft_split_test(char *s, int sep, char **e)
{
	char **r;
	int i;

	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tseparator [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\n", s, sep);

	r = ft_split(s, sep);

	i = 0;
	while (r && r[i])
	{
		printf("expected [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tresult [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\n", e[i], r[i]);
		assert(strcmp(e[i], r[i]) == 0);
		free(r[i]);
		i++;
	}
	free(r);
}
