
#include "libft.h"

/**
 * @brief copies  n bytes from memory area src to memory area dest.
 * 	      The memory areas maybe overlap
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*tmp;

	if (!dest || !src)
		return (0);
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	if (src < dest)
	{
		i = n - 1;
		while (i-- > 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
