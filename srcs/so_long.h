/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:28:51 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/09 19:42:42 by lejulien         ###   ########.fr       */
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

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}

typedef struct	s_img
{
	void		*bg_img;
	void		*player_img;
	void		*bloc_img;
	void		*coll_img;
	void		*mouse_img;
}				t_img;

typedef struct	s_game
{
	t_mlx		*mlx;
	t_img		*img;
	void		*canvas;
	int			mapX;
	int			mapY;
	int			winX;
	int			winY;
}				t_game;

int		game_loop(t_game *game);
void	put_image(void *img, t_game *game, int x, int y);
#endif
