
#include <stdlib.h>

int	ft_char_in(char c, char *s);
int	ft_len_to(char *s);

int	ft_count_word(char *str, char* sep)
{
	int	len;

	len = 0;
    while (*str)
	{
		while (ft_char_in(*str, sep))
			str++;
		if (*str)
			len ++;
		while (!ft_char_in(*str, sep) && *str)
			str++;
	}
	return (len);
}


int	ft_len_to(char *s)
{
	int	len;

	len = 0;
	while (!ft_char_in(s[len], " \t\n") && s[len])
		len++;
	return (len);
}

int	ft_char_in(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	**ft_split(char *str)
{
	char	**ret;
	int	i;
	int	z;
	int	x;
	int	y;

	
	x = ft_count_word(str, " \t\n"); 
	ret = malloc((x + 1) * sizeof(char*));
	ret[0] = 0;
	i = 0;
	while (i < x)
	{
		while (ft_char_in(*str, " \t\n") && *str)
			 str++;

		y = ft_len_to(str);
		if(y)
		{
			ret[i] = malloc((y + 1));
			z = 0;
			while (z < y)
			{
				ret[i][z] = *str;
				z++;
				str++;
			}
			ret[i][z] = 0;

		 	i++;

		}
		
	}
	ret[i] = 0;

	return (ret);
}

