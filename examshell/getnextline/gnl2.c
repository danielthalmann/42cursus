

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1000

int ft_strlen(char *s, char c);


char *ft_concate(char *dest, char *src)
{
	int len_a;
	int len_b;
	char *ret;
	char *init;
	char *dest_init;

	dest_init = dest;

	len_a = ft_strlen(dest, 0);
	len_b = ft_strlen(src, '\n');
	//printf("len [%d]\n", len_a + len_b + 1);
	ret = malloc(len_a + len_b + 1);
	
	init = ret;

	while (len_a--)
		*ret++ = *dest++;
	while (len_b--)
		*ret++ = *src++;
	*ret = 0;
	
	return (init);
}

void ft_move(char *dest, char *src, int len)
{
	char *in;
	in = dest;
	while (*src && len--)
		*dest++ = *src++;
	*dest = 0;
//	printf("ft_move [%s]\n", in);	
}

int ft_strlen(char *s, char c)
{
	int	len;
	len = 0;
	while (*s && *s != c) {
		len++;
		s++;
	}
	if (c != 0 && *s == c){
		len++;
	}
//	printf("len  [%d]\n", len);
	return (len);
}

char *gnl(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *ret;
	char *save;
	int len;

////	printf("start [%s]\n", buf);

	ret = 0;
	save = 0;
	if (!*buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = 0;
	}
	
	len = ft_strlen(buf, '\n');
	if (len < 1)
		return (0);

//	printf("len [%d]\n", len + 1);
	ret = malloc(len + 1);
	ft_move(ret, buf, len);

	while (len > 0 && buf[len -1 ] != '\n')
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = 0;
		//printf("buffer [%s]\n", buf);
		if(len < 1)
			break;
 		len = ft_strlen(buf, '\n');
		save = ret;
		ret = ft_concate(ret, buf);
		free(save);
	}
	ft_move(buf, &buf[len], BUFFER_SIZE);
	return (ret);
}
