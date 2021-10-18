
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && (n - 1))
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}