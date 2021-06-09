/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/09 19:34:34 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int
	load_mlx(t_mlx *mlx, int width, int height)
{
	
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width*64, height*64, "so_long");
	if (!mlx->win_ptr)
		return (1);
	return (0);
}

void
	init_game(t_game *game, t_mlx *mlx, int tileX, int tileY)
{
	game->mlx = mlx;
	game->winX = tileX * 64;
	game->winY = tileY * 64;
}

int
	load_img(t_game *g, t_img *img)
{
	int w;
	int h;

	g->canvas = mlx_new_image(g->mlx->mlx_ptr, g->winX, g->winY);
	img->bg_img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
										"./sprites/aqua.xpm", &w, &h);
	img->player_img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
										"./sprites/dolphin.xpm", &w, &h);
	img->bloc_img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
										"./sprites/bloc.xpm", &w, &h);
	img->coll_img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
										"./sprites/soda.xpm", &w, &h);
	img->mouse_img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
										"./sprites/cursor.xpm", &w, &h);
	if (!img->bg_img || !img->player_img || !img->bloc_img || !img->coll_img ||
		!img->mouse_img)
		return (1);
	g->img = img;
	return (0);
}

int
	close(int keycode, t_game *game)
{
	if (keycode > 10 || keycode < 0) //free data later
		exit(0);
	return (0);
}

int
	main(int ac, char **av)
{
	t_mlx	mlx;
	t_game	game;
	t_img	img;

	init_game(&game, &mlx, 16, 16);
	if (load_mlx(&mlx, 16, 16) || load_img(&game, &img))
		return (1);
	put_image(game.canvas, &game, 5, 5);
	mlx_mouse_hide(mlx.mlx_ptr, mlx.win_ptr);
	mlx_hook(mlx.win_ptr, 17, 0L, close, &game);
	mlx_loop_hook(mlx.mlx_ptr, game_loop, &game);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
