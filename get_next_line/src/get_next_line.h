/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:19:59 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 16:52:49 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);
char			*ft_str_append(char *s, char	*add);
unsigned int	ft_strlen2(char *s, char *eos);
int				ft_fill_buffer(int fd, char *buffer);
char			*ft_allocate(char *buffer, int len);
int				ft_while_not_eol(int fd, char *buffer, char **out);
void			ft_strmov(char *to, char *s, int len);
#endif
