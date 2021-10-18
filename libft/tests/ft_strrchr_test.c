#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strrchr_test(char *s, int search);

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
		ft_strrchr_test(s, s[5]);
		free(s);
		i++;
	}
    ft_strrchr_test("dODsiPvuHFiCQjw", 'i');
	ft_strrchr_test("dODsiPvuHFXCQjw", '~');
}

void ft_strrchr_test(char *s, int search)
{
	char *e;
	char *r;
	e = 0;
	e = strrchr(s, search);
	r = ft_strrchr(s, search);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tsearch [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\n", s, search, e, r);
	if (!e)
		assert(memcmp(&r, &e, sizeof(char*)) == 0);
	else
		assert(strcmp(r, e) == 0);
}
