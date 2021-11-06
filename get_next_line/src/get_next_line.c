/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:31:00 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 16:52:43 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*end;
	unsigned int	len;
	char			*out;

	if (*buffer == 0)
		len = ft_fill_buffer(fd, buffer);
	else
		len = ft_strlen2(buffer, "\n");
	if (!len)
		return (0);
	end = buffer + (len - 1);
	out = ft_allocate(buffer, len);
	if (!out)
		return (0);
	while (len && (*end != '\n' || len == 0))
	{
		len = ft_while_not_eol(fd, buffer, &out);
		end = buffer + (len - 1);
	}
	if (len)
		ft_strmov(buffer, end, len);
	return (out);
}

/**
 * @brief complête la chaine de caractère out en lisant le fd
 * jsqu'à atteindre la fin d'une ligne ou la fin du fichier
 * 
 * @param fd 
 * @param buffer 
 * @param out 
 * @return int 
 */
int	ft_while_not_eol(int fd, char *buffer, char **out)
{
	int		len;
	char	*add;

	len = ft_fill_buffer(fd, buffer);
	if (!len)
		return (0);
	add = ft_allocate(buffer, len);
	if (!add)
		return (0);
	*out = ft_str_append(*out, add);
	free(add);
	return (len);
}

/**
 * @brief Alloue un nouvel espace mémoire de la longueur len et copie du
 * buffer les données vers cet espace mémoire
 * 
 * @param buffer 
 * @param len 
 * @return char* 
 */
char	*ft_allocate(char *buffer, int len)
{
	int		i;
	char	*s;

	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (i < len)
	{
		s[i] = buffer[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * @brief Charge le buffer avec les nouvelles données provenant du fichier
 * et retourne la longueur nécessaire pour contenir la chaine jusqu'à la fin
 * de la ligne ou la fin du fichier
 * 
 * @param fd 
 * @param buffer 
 * @return int Si la valeur retourné est NULL, on a atteint la fin du fichier
 */
int	ft_fill_buffer(int fd, char *buffer)
{
	int	len;

	len = read(fd, buffer, BUFFER_SIZE);
	if (len > -1)
		buffer[len] = 0;
	else
		buffer[0] = 0;
	if (len)
		len = ft_strlen2(buffer, "\n");
	return (len);
}

/**
 * @brief Concatène deux chaines de caractère et libère la mémoire de la 
 * destination
 * 
 * @param s 
 * @param add 
 * @return char* 
 */
char	*ft_str_append(char *s1, char *add)
{
	char	*o;
	char	*so;
	char	*s;

	o = malloc((ft_strlen2(s1, "") + ft_strlen2(add, "") + 1) * sizeof(char));
	if (!o)
		return (0);
	so = o;
	s = s1;
	while (*s)
		*(so++) = *(s++);
	while (*add)
		*(so++) = *(add++);
	*so = 0;
	free(s1);
	return (o);
}
