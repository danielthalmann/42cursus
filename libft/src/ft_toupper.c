
#include "libft.h"

char	*ft_toupper(char *str)
{
	char	*ret;
	int		uplow;

	uplow = 'a' - 'A';
	ret = str;
	while (*str != 0)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - uplow;
		}	
		str++;
	}
	return (ret);
}
