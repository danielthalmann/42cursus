
#include "libft.h"

char	*ft_tolower(char *str)
{
	char	*ret;
	int		uplow;

	uplow = 'a' - 'A';
	ret = str;
	while (*str != 0)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + uplow;
		}	
		str++;
	}
	return (ret);
}
