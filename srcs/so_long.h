/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:28:51 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/09 17:01:57 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_game
{
	t_mlx		*mlx;
	int			tilesizeX;
	int			tilesizeY;
	void		*bg_img;
	void		*player_img;
	void		*bloc_img;
	void		*coll_img;
}				t_game;

#endif
