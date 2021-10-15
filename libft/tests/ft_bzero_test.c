#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <assert.h>
#include "../src/libft.h"
#include "faker.h"

void ft_bzero_test(unsigned int size);

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

	i = -1;
	while (++i < 10)
		ft_bzero_test(i);

}

void ft_bzero_test(unsigned int size)
{
	char	*s;
	char	*s2;
	int		i;

	s = ft_fake_repeat(size + 2, '#');
	printf("size [%d] string [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\t", size, s);
	printf("expected [" ANSI_COLOR_GREEN);
	bzero(s, size);
	i = -1;
	while (++i < size + 2)
		printf("%x ", s[i]);
	printf(ANSI_COLOR_RESET "]\t");	

	s2 = ft_fake_repeat(size + 2, '#');
	printf("obtain [" ANSI_COLOR_GREEN);
	ft_bzero(s2, size);
	i = -1;
	while (++i < size + 2)
		printf("%x ", s2[i]);
	printf(ANSI_COLOR_RESET "]\n");
	
	assert(memcmp(s, s2, size) == 0);
	free(s);
	free(s2);
}

