#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../src/libft.h"
#include "faker.h"

void ft_calloc_test(unsigned int nb, unsigned int size);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{
	int		i;
	(void) argc;
	(void) argv;
	
	i = -1;
	while (++i < 10)
		ft_calloc_test(ft_fake_usint(10), ft_fake_usint(3));
}

void ft_calloc_test(unsigned int nb, unsigned int size)
{
	char	*s;
	char	*s2;
	int		length;
	int		i;

	if (nb == 0)
		nb = 1;
	length = (size * nb);

	s = ft_fake_repeat(length + 2, '#');
	printf("string [" ANSI_COLOR_GREEN "%-20s" ANSI_COLOR_RESET "]\t", s);
	free(s);
	s = calloc(nb, size);
	printf("size [" ANSI_COLOR_GREEN "%d, %d" ANSI_COLOR_RESET "] string [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\t", nb, size, s);
	printf("expected [" ANSI_COLOR_GREEN);
	i = -1;
	while (++i < length)
		printf("%x ", s[i]);
	printf(ANSI_COLOR_RESET "]\t");	
	
	s2 = ft_calloc(nb, size);
	printf("obtain [" ANSI_COLOR_GREEN);
	i = -1;
	while (++i < length)
		printf("%x ", s2[i]);
	printf(ANSI_COLOR_RESET "]\n");
	
	assert(memcmp(s, s2, size) == 0);
	free(s);
	free(s2);
}

