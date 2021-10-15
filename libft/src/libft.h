/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:06:19 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/14 22:06:19 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(const char *str);
void	ft_bzero(void *s, unsigned int n);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
int		ft_isalnum(int c);
int		isalpha(int c);
int		ft_isdigit(int c);

#endif