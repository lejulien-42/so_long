/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:20:48 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 03:00:11 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void
	render_mouse(t_game *game)
{
	int	x;
	int y;

	mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr, &x, &y);
	put_image(game, game->img->mouse_img, set_pos(x, y));
}

int
	game_loop(t_game *game)
{
	render_mouse(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
							game->img->canvas->img_ptr, 0, 0);
	return (0);
}
