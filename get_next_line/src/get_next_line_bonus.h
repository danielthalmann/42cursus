/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:19:59 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 09:54:38 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buffer
{
	char			buf[BUFFER_SIZE + 1];
	int				fd;
	struct s_buffer	*next;
}	t_buffer;
char			*get_next_line(int fd);
char			*ft_str_append(char *s, char	*add);
unsigned int	ft_strlen2(char *s, char *eos);
int				ft_fill_buffer(int fd, char *buffer, t_buffer **list);
char			*ft_allocate(char *buffer, int len);
int				ft_while_not_eol(int fd, char *b, char **out, t_buffer **list);
void			ft_strmov(char *to, char *s, int len);
char			*fd_load_buffer(int fd, t_buffer **list);
long			fd_release_buffer(int fd, t_buffer **list);
#endif
