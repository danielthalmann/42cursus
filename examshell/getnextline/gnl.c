
#define BUFFER_SIZE 10
#include <unistd.h>
#include <stdlib.h>

void	ft_strcpy(char *s1, char *s2, int len)
{
<<<<<<< HEAD
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
=======
	int i;
	i = len - 1;

	while (i > -1)
	{
		s1[i] = s2[i];
		i--;
	}
>>>>>>> 22390c51b4bfa16d5549ccb2bdf8bbaa931c5eb2
}

int	ft_lentoend(char *s)
{
	int len;

	len = 0;
	while (*s && *s != '\n')
	{
		printf("[%c]", *s);
		len++;
		s++;
	}
	if (*s == '\n')
		len++;
	
}


char *gnl(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int		len;
	int		f_len;
	char	*r;
	char	*save;
	printf("gnl \n");
	len = 1;
	buf[0] = 0;
	r = 0;
	save = 0;
	if (!*buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = 0;
		len = ft_lentoend(buf);
		printf("read %d\n", len);
	}
	while (len > 0) 
	{
		if (r)
		{
			save = r;
			f_len = ft_lentoend(r) + len;
		}
		else
			f_len = len;

		r = malloc(f_len + 1);
		r[f_len] = 0;
		if (save)
		{
			ft_strcpy(r, save, ft_lentoend(save));
			free(save);
			ft_strcpy(&r[f_len - len], buf, len);
		}
		else
		{
			ft_strcpy(r, buf, len);
		}
		printf("[%c] [%d]", r[f_len -1 ], f_len);
		if (r[(f_len - 1)] != '\n')
		{
			ft_strcpy(r, buf, len);
			printf("read2\n");
			len = read(fd, buf, BUFFER_SIZE);
			buf[len] = 0;
			len = ft_lentoend(buf);
		} 
	}
	if (len > 0)
	{
		printf("ici %s", buf);
		ft_strcpy(buf, &buf[len], BUFFER_SIZE - len);
		buf[len] = 0;
		

	}
	return (r);
}


