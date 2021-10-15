
#include <stdlib.h> 
#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

//
// copy string and return the end of string
//
char	*ft_strcpy(char *dest, char *src)
{
	while (*src != 0)
	{	
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (dest);
}

int	ft_joinlen(int size, char **strs, char *sep)
{
	int	i;
	int	length;

	length = 0;
	i = -1;
	if (size > 1)
		length += ft_strlen(sep) * (size - 1);
	while (++i < size)
		length += ft_strlen(strs[i]);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	int		i;
	char	*s;
	char	*ret;

	length = 1;
	if (strs && sep)
		length += ft_joinlen(size, strs, sep);
	else
		size = 0;
	s = malloc(length * sizeof(char));
	ret = s;
	i = -1;
	while (++i < size)
	{
		s = ft_strcpy(s, strs[i]);
		if (i < size - 1)
			s = ft_strcpy(s, sep);
	}
	*s = 0;
	return (ret);
}
