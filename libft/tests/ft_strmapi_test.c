#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strmapi_test(char *s);

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
	(void) argc;
	(void) argv;

	i = 5;
	while (i < 10)
	{
		s = ft_fake_printable(i + 6);
		free(s);
		s = ft_fake_printable(i + 5);
		ft_strmapi_test(s);
		free(s);
	i++;
	}

}

char	ft_strmapi_iter(unsigned int i, char c)
{
	(void) i;
	return ft_toupper(c);
}

void	ft_strmapi_test(char *s)
{
	char* e;
	char* r;
	int len;
	int i;

	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\t", s);
	r = ft_strmapi(s, &ft_strmapi_iter);
	len = strlen(s);
	e = malloc(len + 1);
	i = 0;
	while(i < len) 
	{
		e[i] = toupper(s[i]);
		i++;
	}
	e[i] = 0;

	printf("expected [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\n", e, r);

	assert(memcmp(e, r, len + 1) == 0);

	free(e);
	free(r);

}
