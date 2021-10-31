/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:31:00 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/31 13:21:15 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{

	// y a une phase initiale lors de la première lecture de la variable static
	//
	static	char	buffer[BUFFER_SIZE];
	char			*end;
	unsigned int	i;
	unsigned int	len;
	char			*out;
	char			*add;

	// printf("start buffer [%s] ", buffer);

	// si le pointeur de départ est à zéro il faut lire les données
	if (*buffer == 0)
	{
		// rempli le buffer
		len = read(fd, buffer, BUFFER_SIZE - 1);
		buffer[len] = 0; // on fini toujours le buffer par un '\0'

		// printf("len-read[%d] ", len);
		
		// si le buffer est vide, c'est la fin du document
		if (*buffer == 0)
			return (0);
	}

	//
	// fin de la phase initiale


	
	// on lit à présent le buffer avec le pointer jusqu'à la fin de la ligne ou
	// la fin du fichier ou la fin du buffer
	len = ft_strlen2(buffer, "\n");
	// printf("len-buffer[%d] ", len);

	end = buffer + (len - 1);

	// printf("end-buffer[%s] ", end);

	// on crée l'espace mémoire
	out = malloc((len + 1) * sizeof(char));

	// on effectue une copie des données
	i = 0;
	while (i < len)
	{
		out[i] = buffer[i];
		i++;
	}
	out[i] = '\0';
	
	// printf("end-value[%d %c] ", *end, *end);

	// si on est pas à la fin de la ligne ou un retour
	while (*end != '\n' || len == 0)
	{
		// rempli le buffer
		len = read(fd, buffer, BUFFER_SIZE - 1);
		buffer[len] = 0; // on fini toujours le buffer par un '\0'

		len = ft_strlen2(buffer, "\n");
		// printf("len[%d] ", len);
		// printf("BUFFER[%s] ", buffer);
		// si il n'y a plus de caractère, on est à la fin
		if (!len)
			break ;

		end = buffer + (len - 1);

		// on crée l'espace mémoire
		add = malloc((len + 1) * sizeof(char));

		// on effectue une copie des données
		i = 0;
		while (i < len){
			add[i] = buffer[i];
			i++;
		}
		add[i] = '\0';
		// printf("copie [%s] ", add);

		// on duplique le contenu
		out = ft_strappend(out, add);

		free(add);
	}

	// on déplace le reste au début du buffer
	if(len)
	{
		end++;
		len = ft_strlen2(end, "");
		i = 0;
		while (i < len)
		{
			// printf("[%d:%c]", buffer[i], buffer[i]);
			buffer[i] = end[i];
			i++;
		}
		buffer[i] = '\0';
		// printf("actuel buffer [%s]\n", buffer);		
	}

	return (out);
}

/**
 * @brief Concatène deux chaines de caractère et libère la mémoire de la destination
 * 
 * @param s 
 * @param add 
 * @return char* 
 */
char	*ft_strappend(char *s1, char	*add)
{
	char	*o;
	char	*so;
	char	*s;

	o = malloc((ft_strlen2(s1, "") + ft_strlen2(add, "") + 1) * sizeof(char));
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

/**
 * @brief Compte la longueur de la chaine se terminant par '\0' ou 
 * par l'un des caractères contenu dans la chaine eos.
 * le caractère contenu dans eos est compté dans le retour
 * 
 * @param s 
 * @param eos 
 * @return int len of string
 */
unsigned int	ft_strlen2(char *s, char *eos)
{
	unsigned int	c;
	int i;
	int p; // present in char

	c = 0;
	p = 0;
	while(*s && !p)
	{
		i = 0;
		while (eos[i])
		{
			if (eos[i] == *s)
			{
				p = 1;
				break ;
			}
			i++;
		}
		c++;
		s++;
	}
	return c;
}