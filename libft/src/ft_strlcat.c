
#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*(dest++) = *(src++);
	}
	*dest = 0;
	return (ret);
}
