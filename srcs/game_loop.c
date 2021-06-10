/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:20:48 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 18:37:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void
	draw_map(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (y++ < game->mapY - 1)
	{
		x = -1;
		while (x++ < game->mapX - 1)
		{
			put_image(game, game->img->bg_img, set_pos(x * 64, y * 64));
			if (game->map[y * game->mapX + x] == '1')
				put_image(game, game->img->bloc_img, set_pos(x * 64, y * 64));
			else if (game->map[y * game->mapX + x] == 'P')
				put_image(game, game->img->player_img, set_pos(x * 64, y * 64));
			else if (game->map[y * game->mapX + x] == 'C')
				put_image(game, game->img->coll_img, set_pos(x * 64, y * 64));
			else if (game->map[y * game->mapX + x] == 'E')
				put_image(game, game->img->portal_img, set_pos(x * 64, y * 64));
		}
	}
}

void
	render_mouse(t_game *game)
{
	int	x;
	int y;

	mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr, &x, &y);
	if (x < game->winX - game->img->mouse_img->width && x > 0 &&
		y < game->winY - game->img->mouse_img->height && y > 0)
		put_image(game, game->img->mouse_img, set_pos(x, y));
}

int
	game_loop(t_game *game)
{
	draw_map(game);
	render_mouse(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
							game->img->canvas->img_ptr, 0, 0);
	return (0);
}
