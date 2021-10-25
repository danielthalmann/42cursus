#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"
#include <fcntl.h>

void ft_putstr_fd_test(char *s);

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
	while (i < 40)
	{
		s = ft_fake_printable(i + 5);
		ft_putstr_fd_test(s);
		free(s);
		i += 4;
	}

}

void ft_putstr_fd_test(char *s)
{
	int file_handle;
	char *buff;
	int length;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	file_handle = open("_test.txt", O_WRONLY | O_APPEND | O_CREAT, mode);
	if(file_handle == -1)
		return ;
	ft_putstr_fd(s, file_handle);
	close(file_handle);

	file_handle = open("_test.txt", O_RDONLY);
	if(file_handle == -1)
		return ;
	buff = ft_fake_repeat(255, 0);
	length = read(file_handle, buff, 255);
	buff[length] = 0;
	printf("expected [" ANSI_COLOR_GREEN "%10s" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", s, buff);
	close(file_handle);
	unlink("_test.txt");

	assert(strcmp(s, buff) == 0);

	free(buff);
}
