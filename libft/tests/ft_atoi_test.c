#include <stdio.h>
#include <stdlib.h>
#include "../src/libft.h"
#include "faker.h"
#include <assert.h>

void ft_atoi_test(char *s);

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
	while (i <10)
	{
		s = ft_fake_strnum(i);
		ft_atoi_test(s);
		free(s);
		i++;
	}
	ft_atoi_test("-+-+234");
	ft_atoi_test("sdgf");
	ft_atoi_test("");
	ft_atoi_test("2d");
	ft_atoi_test("21474836478");
	
}

void ft_atoi_test(char *s)
{
	int r;
	int e;
	r = ft_atoi(s);
	e = atoi(s);
	printf("string [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%11d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%11d" ANSI_COLOR_RESET "]\n", s, e, r);
	assert(r == e);
}

