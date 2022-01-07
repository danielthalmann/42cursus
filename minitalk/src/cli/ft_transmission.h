/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmission.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:17:10 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/07 11:03:33 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSMISSION_H
# define FT_TRANSMISSION_H

typedef struct s_transmission
{
	char	*str;
	int		octet;
	int		pid;
	int		send;
}	t_transmission;
t_transmission	*ft_get_transmission(void);
void			ft_clean_transmission(t_transmission *t);
#endif
