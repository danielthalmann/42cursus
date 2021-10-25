#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strchr_test(char *s, int search);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{

	char *s;
	int i;
	(void) argc;
	(void) argv;
	
	i = -1;
	while (i < 10)
	{
		s = ft_fake_alpha(15);
		ft_strchr_test(s, s[5]);
		free(s);
		i++;
	}
	ft_strchr_test("dODsiPvuHFXCQjw", '~');
	ft_strchr_test("dODsiPvuHFXCQjw", 0);
}

void ft_strchr_test(char *s, int search)
{
	char *e;
	char *r;
	e = 0;
	e = strchr(s, search);
	r = ft_strchr(s, search);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tsearch [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\n", s, search, e, r);
	if (!e)
		assert(memcmp(&r, &e, sizeof(char*)) == 0);
	else
		assert(strcmp(r, e) == 0);
}
