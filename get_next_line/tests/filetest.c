/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:32:24 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/31 14:10:34 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>

char	*ft_fake_alpha(unsigned int size);

int	main(int argc, char ** argv)
{
   
    int     chars;
    int     lines;
    char    *l;
    int     i;

    if (argc == 1)
    {
        printf("generate a file with 2 arguments. The first argument is the length of line and the second is the number of line.\n");
        exit(0);
    }

    if (argc < 3)
    {
        printf("Error : %s\n", strerror(EINVAL));
        exit(1);
    }

    chars = atoi(argv[1]);
    lines = atoi(argv[2]);

    i = 0;
    srand(time(NULL));
    while (i < lines)
    {
        l = ft_fake_alpha((((float)rand() / RAND_MAX) * chars));
        if(i)
            printf("\n%s", l);
        else
            printf("%s", l);
        free(l);
        i++;
     }

}

/**
 * @brief generate a string with alpha caracter of length define in size
 * 
 * @param size length of string
 * @return char* 
 */
char	*ft_fake_alpha(unsigned int size)
{
	unsigned int		i;
	int		pos;
	char	*alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	*s;
    static int  y;

	s = malloc((size + 1) * sizeof(char));
	srand(time(NULL)+y);
    y++;
	i = 0;
	while (i < size)
	{
		pos = (((float)rand() / RAND_MAX) * 52);
		s[i] = alpha[pos];
		i++;
	}
	s[size] = 0;
	return s;
}
