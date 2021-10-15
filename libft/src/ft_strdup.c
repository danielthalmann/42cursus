
#include <stdlib.h> 
#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*src != 0)
	{	
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		length;
	char	*dest;

	length = ft_strlen(src);
	dest = (malloc((length + 1) * sizeof (char)));
	ft_strcpy(dest, src);
	return (dest);
}
