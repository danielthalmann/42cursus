/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/01 15:14:39 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_H
# define SCORE_H
# define SCORE_SPRITE_WIDTH 25
# define SCORE_SPRITE_HEIGHT 40

int		ft_init_score(t_game *game);
void	ft_score_load_sprite(char *f, t_game *game);
void	ft_free_score(t_score *score);
void	ft_draw_score_init(t_score *score, t_gl *gl);
void	ft_draw_score(t_score *score, t_game *game, t_gl *gl);
#endif
