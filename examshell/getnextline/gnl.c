
#define BUFFER_SIZE 10
#include <unistd.h>

char *gnl(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int len;
	char *ret;

	ret = 0;
	len = 1;
	if (!*buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = 0;
		len = ft_lentoend(buf);
	}
	while (len > 0) 
	{
		malloc
	}
	return (ret);
}

int	ft_lentoend(char *s)
{
	int len;

	len = 0;
	while (*s && *s != '\n')
	{
		len++;
		s++;
	}
	if (*s == '\n')
		len++;
	
}

