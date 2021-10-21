#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_strlen_test(char *str2);

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

	ft_strlen_test("1234");
	for(int i = 0; i < 25; i++)
	{
		f = ft_fake_printable(i);
		ft_strlen_test(f);
		free(f);		
	}

}

void ft_strlen_test(char *str2)
{

	int	r;
	int	e;
	e = strlen(str2);
	r = ft_strlen(str2);
	printf("string [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\t expected [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\n", str2, e, r);

	assert(r == e);

}
