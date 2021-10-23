#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_substr_test(char *s, int start, int len, char *e);

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
	
    ft_substr_test("Bonjour Monsieur", 3, 4, "jour");
	ft_substr_test("", 3, 4, "");
	ft_substr_test("Bonjour", 5, 4, "ur");
	ft_substr_test("Bonjour", 0, 1, "B");
	ft_substr_test("Bonjour", 5, 0, "");
	ft_substr_test("", 5, 2, "");

}

void ft_substr_test(char *s, int start, int len, char *e)
{
	char *r;

	r = ft_substr(s, start, len);
	printf("string [" ANSI_COLOR_GREEN "%16s" ANSI_COLOR_RESET "]\t start [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tlen [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]", s, start, len);
	printf("\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", e, r);
	assert(strcmp(r, e) == 0);
	free(r);
}
