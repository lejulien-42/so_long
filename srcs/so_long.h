/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:28:51 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 02:48:52 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_img_d
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img_d;


typedef struct	s_img
{
	t_img_d		*bg_img;
	t_img_d		*player_img;
	t_img_d		*bloc_img;
	t_img_d		*coll_img;
	t_img_d		*canvas;
	t_img_d		*mouse_img;
}				t_img;

typedef struct	s_game
{
	t_mlx		*mlx;
	t_img		*img;
	int			mapX;
	int			mapY;
	int			winX;
	int			winY;
}				t_game;

int		game_loop(t_game *game);
t_vec2	set_pos(int x, int y);
void	put_image(t_game *g, t_img_d *to_place, t_vec2 pos);

#endif
