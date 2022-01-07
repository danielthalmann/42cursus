/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:17:10 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/05 09:17:10 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNUM_H
# define FT_SIGNUM_H
# ifndef    SIGUSR1
#  define   SIGUSR1                10
# endif
# ifndef    SIGUSR2
#  define   SIGUSR2                12
# endif
typedef struct s_transmission
{
	char	*str;
	int		octet;
	int		pid;
}	t_transmission;

#endif
