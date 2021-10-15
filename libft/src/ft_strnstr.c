
#include "libft.h"


int	compare(char a, char b)
{
	if (a == b)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	same;

	if (!*to_find)
		return (str);
	while (*str)
	{
		i = 0;
		same = 1;
		while (to_find[i])
		{
			same = compare(to_find[i], str[i]);
			if (!same)
			{
				break ;
			}
			i++;
		}
		if (same)
		{
			return (str);
		}	
		str++;
	}
	return (0);
}
