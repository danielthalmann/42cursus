#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strtrim_test(char *s, char *trim, char *e);

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
	
    ft_strtrim_test(" tHello  b", " bt", "Hello");
	ft_strtrim_test("~~dOD~siPvuHF-End~~~", "~", "dOD~siPvuHF-End");
	ft_strtrim_test("~~dOD~siPvuHF-End~~~", "", "~~dOD~siPvuHF-End~~~");
	ft_strtrim_test("autre chose autre", "autre", " chose ");
	ft_strtrim_test("", "autre", "");
}

void ft_strtrim_test(char *s, char *trim, char *e)
{
	char *r;

	r = ft_strtrim(s, trim);
	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\ttrim [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, trim, e, r);
	assert(strcmp(r, e) == 0);
	free(r);
}
