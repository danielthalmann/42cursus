
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_readline(int file_handle, char *buffer);

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Nombre d'argument invalide\n");
		return (0);
	}
	for (int i = 2; i < argc; i++)
	{
		int file_handle;
		file_handle = open(argv[i], O_RDONLY);
		printf("%s\n", argv[i]);	
		if(file_handle == -1)
		{
			printf("Impossible d'ouvrir le fichier (%s).\n", argv[i]);
		}
		else
		{
			char buffer[256];
			int r;
			do
			{
				r = ft_readline(file_handle, buffer);
				printf("%s\n", buffer);	
			} while (r);
		}
		close(file_handle);
	}
	return (0);
}

int	ft_readline(int file_handle, char *buffer)
{
	char c;
	int r;

	do
	{
		r = read(file_handle, &c, 1);
		if(!r)
			c = 0;
		if (c == '\n')
			c = 0;
		if (c != '\r')
			*buffer = c;
		buffer++;
	}
	while (c);
	return (r);
}

