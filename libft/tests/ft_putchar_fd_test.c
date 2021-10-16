#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include "../src/libft.h"
#include "faker.h"
#include <fcntl.h>

void ft_putchar_fd_test(char c);

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
		s = ft_fake_alphanum(1);
		ft_putchar_fd_test(*s);
		free(s);
		i++;
	}

}

void ft_putchar_fd_test(char c)
{
	int file_handle;
	char *buff;

	buff = ft_fake_repeat(255, '#');
	file_handle = open("_test.txt", O_WRONLY | O_APPEND | O_CREAT);
	if(file_handle == -1)
		return ;
	ft_putchar_fd(c, file_handle);
	close(file_handle);

	file_handle = open("_test.txt", O_RDONLY);
	if(file_handle == -1)
		return ;
	read(file_handle, buff, 1);
	printf("expected [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\tobtain [" ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET "]\n", c, *buff);
	close(file_handle);
	unlink("_test.txt");
	
	assert(c == *buff);

	free(buff);

	
}
