/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/09 04:26:12 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
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
	key_hook(int keycode, void *ptr)
{
	*((int *)ptr) = keycode;
	printf("the pressed key is : %d\n", keycode);
	return (0);
}

int
	loop_hook(void *ptr)
{
	printf("%d\n", *((int *)ptr));
}

int
	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*bg_img;
	void	*bloc_img;
	void	*player_img;
	void	*coll_img;
	int		x;
	int		y;
	int		key;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	bg_img = mlx_xpm_file_to_image(mlx_ptr, "./sprites/aqua.xpm", &x, &y);
	player_img = mlx_xpm_file_to_image(mlx_ptr, "./sprites/dolphin.xpm", &x, &y);
	bloc_img = mlx_xpm_file_to_image(mlx_ptr, "./sprites/bloc.xpm", &x, &y);
	coll_img = mlx_xpm_file_to_image(mlx_ptr, "./sprites/soda.xpm", &x, &y);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH * 64, HEIGHT * 64, "so_long");
	int i = 0;
	int j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (map[j][i] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, bloc_img, i * 64, j * 64);
			else if (map[j][i] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, player_img, i * 64, j * 64);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, coll_img, i * 64, j * 64);
			else
				mlx_put_image_to_window(mlx_ptr, win_ptr, bg_img, i * 64, j * 64);
			i++;
		}
		j++;
	}
	mlx_key_hook(mlx_ptr, key_hook, &key);
	mlx_loop_hook(mlx_ptr, loop_hook, &key);
	mlx_loop(mlx_ptr);
	return (0);
}
