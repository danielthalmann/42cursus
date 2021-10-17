#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"

void ft_striteri_test(char *s);

/**
 * @brief main test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char** argv)
{

	char	*s;
	int		i;
	(void) argc;
	(void) argv;

	i = 5;
	while (i < 10)
	{
		s = ft_fake_printable(i + 5);
		ft_striteri_test(s);
		free(s);
		i++;
	}

}

void	ft_striteri_iter(unsigned int i, char *s)
{
	int file_handle;
	char buff[255];

	file_handle = open("_test.txt", O_RDONLY);
	if(file_handle == -1)
		return ;
	read(file_handle, buff, strlen(s) + 1);
	close(file_handle);

	printf("obtain I : [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\texpected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", i, s, buff);

	assert(strcmp(&buff[i], s) == 0);
}

void	ft_striteri_test(char *s)
{
	int file_handle;
	file_handle = open("_test.txt", O_WRONLY | O_CREAT);
	printf("d: %d\n", file_handle);
	if(file_handle == -1)
		return ;
	write(file_handle, s, strlen(s)+1);
	close(file_handle);

	printf("string [" ANSI_COLOR_GREEN "%15s" ANSI_COLOR_RESET "]\n", s);
	ft_striteri(s, &ft_striteri_iter);

	unlink("_test.txt");
}
