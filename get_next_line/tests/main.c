/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:32:24 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/29 17:41:03 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	main()
{
    int     fd;
    char    *line;

    fd = open("case00.txt", O_RDONLY, O_NONBLOCK);

    if (fd == -1)
    {

        line = get_next_line(fd);

    }

    close(fd);

}