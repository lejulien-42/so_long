/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:20:48 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/11 19:33:19 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void
	handle_moves(t_game *game)
{
	if (game->key_w && game->player_pos.y != 0 &&
		game->map[(game->player_pos.y - 1) * game->mapX + game->player_pos.x] != '1')
	{
		game->player_pos.y--;
		game->key_w = 0;
	}
	if (game->key_a && game->player_pos.x != 0 &&
		game->map[game->player_pos.y * game->mapX + (game->player_pos.x - 1)] != '1')
	{
		game->player_pos.x--;
		game->key_a = 0;
	}
	if (game->key_s && game->player_pos.y != game->mapY &&
		game->map[(game->player_pos.y + 1) * game->mapX + game->player_pos.x] != '1')
	{
		game->player_pos.y++;
		game->key_s = 0;
	}
	if (game->key_d && game->player_pos.x != game->mapX &&
		game->map[game->player_pos.y * game->mapX + (game->player_pos.x + 1)] != '1')
	{
		game->player_pos.x++;
		game->key_d= 0;
	}
}

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
			else if (game->map[y * game->mapX + x] == 'C')
				put_image(game, game->img->coll_img, set_pos(x * 64, y * 64));
			else if (game->map[y * game->mapX + x] == 'E')
				put_image(game, game->img->portal_img, set_pos(x * 64, y * 64));
		}
	}
	put_image(game, game->img->player_img, set_pos(game->player_pos.x * 64,
													game->player_pos.y * 64));
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
	handle_moves(game);
	draw_map(game);
	render_mouse(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
							game->img->canvas->img_ptr, 0, 0);
	return (0);
}
