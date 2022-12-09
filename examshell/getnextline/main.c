
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "gnl2.c"

int main(int argc, char **argv)
{
	char *s;

	if (argc != 2)
		return (0);

	int fd;
	fd = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR);

	if (fd)
	{
		while ((s = gnl(fd)))
		{
			printf("l:%s", s);

		}
		
	}

	close(fd);

	return (0);

}