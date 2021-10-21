#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <bsd/string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strlcpy_test(char *str2, size_t size);

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
	char *f;

	f = ft_fake_alphanum(4);
	ft_strlcpy_test(f, 4);
	free(f);
	ft_strlcpy_test("1234", 7);
	ft_strlcpy_test("1234567890", 5);
	ft_strlcpy_test("", 15);
	ft_strlcpy_test("23849284", 15);
	f = ft_fake_printable(5);
	ft_strlcpy_test(f, 15);
	free(f);
	ft_strlcpy_test("1234", 1);
	ft_strlcpy_test("12345", 1);
	ft_strlcpy_test("1234", 1);
	ft_strlcpy_test("1234", 1);
	ft_strlcpy_test("1234", 1);


}

void ft_strlcpy_test(char *str2, size_t size)
{
	char	*se1;
	char	*se2;
	char	*s1;
	char	*s2;

	se1 = malloc(20);
	memset(se1, '#', 20);
	se2 = malloc(10);
	memset(se2, '#', 10);
	strcpy(se2, str2);

	s1 = malloc(20);
	memset(s1, '#', 20);
	s2 = malloc(10);
	memset(s2, '#', 10);
	strcpy(s2, str2);

	int	r;
	int	e;
	printf("size [" ANSI_COLOR_GREEN "%ld" ANSI_COLOR_RESET "]\tstring [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\t", size, str2);
	e = strlcpy(se1, se2, size);
	r = ft_strlcpy(s1, s2, size);
	printf("expected string[" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\t ret [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tobtain string [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tret [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\n", se1, e, s1, r);
	
	assert(memcmp(se1, s1, 20) == 0);
	assert(r == e);

	free(se1);
	free(se2);

	free(s1);
	free(s2);
}
