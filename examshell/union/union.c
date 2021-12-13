
#include <unistd.h>


char	*ft_exists(char *s, char c, int len);

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	s1 = argv[1];
	s2 = argv[2];

	i = 0;

	while (s1[i])
	{
		if (i > 0)
		{
			if (!ft_exists (s1, s1[i], i))
			{
				write (1, &s1[i], 1);
			}
		}
		else 
			write (1, &s1[i], 1);
		i++;
	}

	i = 0;
	while (s2[i])
	{
		if (!ft_exists (s1, s2[i], 0))
		{
			if (i > 0)
			{
				if (!ft_exists (s2, s2[i], i))
				{
					write (1, &s2[i], 1);
				}
			}
			else 
				write (1, &s2[i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_exists(char *s, char c, int len)
{
	int	i;

	i = 0;
	while (*s && (i < len || len == 0))
	{
		if (*s == c)
			return (s);
		s++;
		i++;
	}
	return (0);
}

