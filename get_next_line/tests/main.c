/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:32:24 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/29 22:11:36 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	main()
{
    printf("%d\n", BUFFER_SIZE);

/*

    int     fd;
    char    *l;

    
    fd = open("case00.txt", O_RDONLY);

    if (fd == -1)
    {
        while (l)
            l = get_next_line(fd);
    }

    close(fd);
*/

}