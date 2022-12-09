
#include <unistd.h>

int ft_is_present(char *s, char c, int len)
{
	int start;

	start = 0;
	while (s[start] && start < len)
	{
		if (s[start] == c)
			return (1);
		start++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;

	return (len);
		
}

int main( int argc, char **argv)
{
	int p;
	int l2;


	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	l2 = ft_strlen(argv[2]);
	p = 0;
	while(argv[1][p])
	{
		if (p == 0)
			write(1, &argv[1][p], 1);
		else
		{
			if (!ft_is_present(argv[1], argv[1][p], p))
			{
				if (ft_is_present(argv[2], argv[1][p], l2))
					write(1, &argv[1][p], 1);
			}
		}
		p++;
	}
}

