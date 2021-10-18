#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <bsd/string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strnstr_test(char *s, char *f, unsigned int l);

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
	
    ft_strnstr_test("bonjour", "on", 4);
    ft_strnstr_test("bonjour", "jour", 3);
    ft_strnstr_test("bonjour", "jour", 12);
    ft_strnstr_test("bonjour", "jour", 0);
	
}

void ft_strnstr_test(char *s, char *f, unsigned int l)
{
	char *e;
	char *r;
	e = strnstr(s, f, l);
	r = ft_strnstr(s, f, l);
	printf("string [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s,  e, r);
	//assert(r == e);
}
