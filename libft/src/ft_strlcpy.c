
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
