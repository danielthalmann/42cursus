/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:32:24 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 16:53:18 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int	main(int argc, char **argv)
{

    int     *fd;
    char    *l;
	int		i,y;
	int		len;
	char	*files[] = {"case00.txt", "case03.txt"};
	int		quit = 0;

	(void) argv;
	(void) argc;
/*
    if (argc == 1)
    {
        l = get_next_line(1);
        while(l)
        {
            printf("%s", l);
            free(l);
            l = get_next_line(1);   
        }
        free(l);
        return (0);
    }
*/
	//len = argc - 1;
	len = 2;

 	get_next_line(1000);

    if (len > 0)
    {
		fd = malloc((len)* sizeof(int));

		i = 0;
		while (i < (len))
		{
			fd[i] = open(files[i], O_RDONLY);
        	if (fd[i] == -1)
			{
				printf("%s", strerror(errno));
				return (errno);
			}
			i++;
		}
		i = 0;

		while (i < (len) && !quit)
        {
			if (fd[i])
			{
//				printf("fd[y] : %d\n", fd[i]);
				l = get_next_line(fd[i]);
				if (l)
				{
					printf("%s", l);
					free(l);
				}
				else
				{
					close(fd[i]);
					fd[i] = 0;
				}
			}

			i++;
			if (i == len)
				i = 0;
			
			quit = 1;
			y = 0;
			while (y < (len))
        	{
//				printf("fd[y] : %d\n", fd[y]);
				if (fd[y])
					quit = 0;

				y++;
			}
        }

		i = 0;
		while (i < (len))
		{
			close(fd[i]);
			i++;
		}
		free(fd);
    }
}
