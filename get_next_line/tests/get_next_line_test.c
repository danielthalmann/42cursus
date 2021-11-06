/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:32:24 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 16:53:37 by dthalman         ###   ########.fr       */
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

    int     fd;
    char    *l;

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

    if (argc == 2)
    {

        fd = open(argv[1], O_RDONLY);

        if (fd != -1)
        {

            l = get_next_line(fd);
            while(l)
            {
                printf("%s", l);
                free(l);
                l = get_next_line(fd);
            }
            free(l);
        }
        else 
        {
            printf("%s", strerror(errno));
        }

        close(fd);

    }

}
