
#include <stdlib.h>
#include "libft.h"

int	ft_is_separation(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_to_next_separation(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str && !ft_is_separation(*str, charset))
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_count_separation(char *str, char *charset)
{
	int		count;
	char	last;
	char	*c;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_separation(*str, charset))
			str++;
		count++;
		str++;
		while (*str && !ft_is_separation(*str, charset))
			str++;
	}
	return (count);
}

char	*ft_split_strcopy(char *dest, char *str, char *charset)
{
	int	j;

	j = 0;
	while (*str && !ft_is_separation(*str, charset))
	{
		dest[j++] = *str;
		str++;
	}
	dest[j++] = 0;
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		count;
	int		i;
	int		j;
	int		str_len;

	count = ft_count_separation(str, charset);
	ret = malloc((count + 1) * sizeof(char *));
	i = 0;
	ret[i] = 0;
	while (i < count)
	{
		while (*str && ft_is_separation(*str, charset))
			str++;
		str_len = ft_count_to_next_separation(str, charset);
		if (str_len)
		{
			ret[i] = malloc((str_len + 1) * sizeof(char));
			str = ft_split_strcopy(ret[i], str, charset);
			i++;
		}
		str++;
	}
	ret[i] = 0;
	return (ret);
}
