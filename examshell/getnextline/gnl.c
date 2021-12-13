
#define BUFFER_SIZE 10
#include <unistd.h>

char *gnl(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int len;
	
	len = 1;
	if (!*buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
	}
	if (len < 1) 
	{
		return (0);
	}
	
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

