/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:23:55 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/11 23:52:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef unsigned int	t_uint;
typedef struct s_position
{
	t_uint	x;
	t_uint	y;
}	t_position;
typedef struct s_size
{
	t_uint	width;
	t_uint	height;
}	t_size;
#endif