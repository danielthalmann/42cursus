
#include <unistd.h>
#include <stdio.h>
#include "ft_split.c"

int	main(int argc, char **argv)
{
	char **s;

	if (argc == 2)
	{
		s = ft_split(argv[1]);
		while ( *s )
		{
			printf("%s\n", *s);
			s++;
		}
	}
}
