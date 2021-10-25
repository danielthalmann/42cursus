#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_memchr_test(char *s, int search, int size);

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
	
	
	char	m2[] = {0, 0, 2, 0};
	ft_memchr_test(m2, 2 + 256, 4);

	i = -1;
	while (i < 10)
	{
		s = ft_fake_alpha(15);
		ft_memchr_test(s, s[5], 15);
		free(s);
		i++;
	}
	ft_memchr_test("dODsiPvuHFXCQjw", '~', 15);

}

void ft_memchr_test(char *s, int search, int size)
{
	char *e;
	char *r;
	e = 0;
	e = memchr(s, search, size);

	r = ft_memchr(s, search, size);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tsearch [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\n", s, search, e, r);
	if (!e)
		assert(memcmp(&r, &e, sizeof(char*)) == 0);
	else
		assert(strcmp(r, e) == 0);
}
