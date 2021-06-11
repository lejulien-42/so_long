/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/11 20:37:36 by user42           ###   ########.fr       */
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
	game->coll = 0;
}

t_img_d
	*create_and_get_date(t_game *g, t_img *img, char *path)
{
	t_img_d	*ret;

	ret = malloc(sizeof(t_img_d));
	if (!ret)
		return (NULL);
	if (!path)
		ret->img_ptr = mlx_new_image(g->mlx->mlx_ptr, g->winX, g->winY);
	else
		ret->img_ptr = mlx_xpm_file_to_image(g->mlx->mlx_ptr, path, &ret->width,
											&ret->height);
	if (!ret->img_ptr)
		return (NULL);
	ret->data = (int *)mlx_get_data_addr(ret->img_ptr, &ret->bpp, &ret->size_l,
										&ret->endian);
	return (ret);
}

int
	load_img(t_game *g, t_img *img)
{
	img->canvas = create_and_get_date(g, img, NULL);
	img->bg_img = create_and_get_date(g, img, "./sprites/aqua.xpm");
	img->player_img = create_and_get_date(g, img, "./sprites/dolphin.xpm");
	img->bloc_img = create_and_get_date(g, img, "./sprites/bloc.xpm");
	img->coll_img = create_and_get_date(g, img, "./sprites/soda.xpm");
	img->mouse_img = create_and_get_date(g, img, "./sprites/cursor.xpm");
	img->portal_img = create_and_get_date(g, img, "./sprites/portal.xpm");
	if (!img->bg_img || !img->player_img || !img->bloc_img || !img->coll_img ||
		!img->mouse_img || !img->canvas || !img->portal_img)
		return (1);
	g->img = img;
	return (0);
}

void
	load_coll(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (y++ < game->mapY - 1)
	{
		x = -1;
		while (x++ < game->mapX - 1)
		{
			if (game->map[y * game->mapX + x] == 'C')
				count++;
		}
	}
	game->t_coll = count;
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
	t_vec2	mapSize;

	if (ac == 2)
	{
		ft_getmap(&game, av[1]);
		if (game.map == NULL)
			return (ft_put_error());
		if (mapSize.x == -1)
			return (ft_put_error());
		get_player_pos(&game);
		load_coll(&game);
		init_game(&game, &mlx, game.mapX, game.mapY);
		if (load_mlx(&mlx, game.mapX, game.mapY) || load_img(&game, &img))
			return (ft_put_error());
		mlx_mouse_hide(mlx.mlx_ptr, mlx.win_ptr);
		mlx_hook(mlx.win_ptr, 02, (1L<<0), key_pressed, &game);
		mlx_hook(mlx.win_ptr, 03, (1L<<1), key_released, &game);
		mlx_hook(mlx.win_ptr, 17, 0L, close, &game);
		mlx_loop_hook(mlx.mlx_ptr, game_loop, &game);
		mlx_do_sync(mlx.mlx_ptr);
		mlx_loop(mlx.mlx_ptr);
		return (0);
	}
	return (ft_put_error());
}
