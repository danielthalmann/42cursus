#include <stdio.h>
#include <stdlib.h>
#include "../src/libft.h"
#include "faker.h"

void ft_isalnum_test(char *s);

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

	i = -1;
	while (i <10)
	{
		s = ft_fake_strnum(i);
		ft_isalnum_test(s);
		free(s);
		i++;
	}
	ft_isalnum_test("-+-+234");
	ft_isalnum_test("sdgf");
	ft_isalnum_test("");
	ft_isalnum_test("2d");
	ft_isalnum_test("21474836478");
	
}

void ft_isalnum_test(char *s)
{
	int r;
	int e;
	r = ft_isalnum(s);
	e = isalnum(s);
	printf("string [" ANSI_COLOR_GREEN "%11s" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%11d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%11d" ANSI_COLOR_RESET "]\n", s, e, r);
}

