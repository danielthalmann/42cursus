#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"
#include <fcntl.h>

void ft_putendl_fd_test(char *s);

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

	i = -1;
	while (i < 10)
	{
		s = ft_fake_alphanum(i + 5);
		ft_putendl_fd_test(s);
		free(s);
		i++;
	}

}

void ft_putendl_fd_test(char *s)
{
	int file_handle;
	char *buff;
	int length;

	buff = ft_fake_repeat(255, '#');
	file_handle = open("_test.txt", O_WRONLY | O_APPEND | O_CREAT);
	if(file_handle == -1)
		return ;
	ft_putendl_fd(s, file_handle);
	close(file_handle);

	file_handle = open("_test.txt", O_RDONLY);
	if(file_handle == -1)
		return ;
	length = read(file_handle, buff, 255);
	buff[length] = 0;
	printf("expected [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "\n]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, buff);
	close(file_handle);
	unlink("_test.txt");

	assert(strlen(s) == strlen(buff) - 1);
	assert(buff[strlen(buff) - 1] == '\n');
	assert(strncmp(s, buff, strlen(s)) == 0);

	free(buff);
}