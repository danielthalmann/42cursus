#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"
#include <fcntl.h>

void ft_putnbr_fd_test(int i, char *s);

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
		s = ft_fake_strnum(i);
		ft_putnbr_fd_test(atoi(s), s);
		free(s);
		i++;
	}
	i = -1;

}


void ft_putnbr_fd_test(int i, char *s)
{
	int file_handle;
	char *buff;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	
	file_handle = open("_test.txt", O_WRONLY | O_APPEND | O_CREAT, mode);
	if(file_handle == -1)
		return ;
	ft_putnbr_fd(i, file_handle);
	close(file_handle);

	file_handle = open("_test.txt", O_RDONLY);
	if(file_handle == -1)
		return ;
	buff = ft_fake_repeat(255, 0);
	int len = read(file_handle, buff, 255);
	buff[len] = 0;
	printf("len [%d] expected [" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "]\n", len, i, buff);
	close(file_handle);
	unlink("_test.txt");
	
	assert(strcmp(s, buff) == 0);

	free(buff);

}
