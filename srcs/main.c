/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/09 17:08:05 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#define WIDTH 20
#define HEIGHT 10


char map[HEIGHT + 1][WIDTH + 1] =  {"11111111111111111111",
									"10C0100000C00000C001",
									"1000100P000000000001",
									"10C00000001111111101",
									"111111111100C0000001",
									"10000000001111111101",
									"10111111100000000101",
									"10111111111111111101",
									"10000000000000000001",
									"11111111111111111111"};

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
	init_game(t_game *game, t_mlx *mlx)
{
	game->mlx = mlx;
	game->tilesizeX = 64;
	game->tilesizeY = 64;
	game->bg_img = NULL;
	game->player_img = NULL;
	game->bloc_img = NULL;
	game->coll_img = NULL;
}

int
	load_img(t_game *game)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
										"./sprite/aqua.xpm",
										&game->tilesizeX,
										&game->tilesizeY);
	game->player_img = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
										"./sprite/dolphin.xpm",
										&game->tilesizeX,
										&game->tilesizeY);
	game->bloc_img = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
										"./sprite/bloc.xpm",
										&game->tilesizeX,
										&game->tilesizeY);
	game->coll_img = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
										"./sprite/soda.xpm",
										&game->tilesizeX,
										&game->tilesizeY);
	if (!game->bg_img || !game->player_img || !game->bloc_img ||
										!game->coll_img)
		return (0);
	return (0);
}

int
	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_game	*game;

	mlx = malloc(sizeof(t_mlx));
	game = malloc(sizeof(t_game));
	if (load_mlx(mlx, WIDTH, HEIGHT))
		return (1);
	init_game(game, mlx);
	if (load_img(game))
		return (1);
	/*
	int i = 0;
	int j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
	printf("segfault\n");
			if (map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->bloc_img, i * 64, j * 64);
			else if (map[j][i] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->player_img, i * 64, j * 64);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->coll_img, i * 64, j * 64);
			else
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->bg_img, i * 64, j * 64);
			i++;
		}
		j++;
	}*/
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, game->bloc_img, 64, 64);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
