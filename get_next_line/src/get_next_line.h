/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:31:13 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/31 09:57:59 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif
char			*get_next_line(int fd);
char			*ft_strappend(char *s, char	*add);
unsigned int	ft_strlen2(char *s, char *eos);
#endif