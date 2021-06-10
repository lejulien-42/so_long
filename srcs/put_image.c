/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:26:10 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 03:11:53 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// i for canvas
// j for image

void
	put_image(t_game *g, t_img_d *to_place, t_vec2 pos)
{
	int i;
	int j;
	int x;
	int y;

	j = -1;
	y = -1;
	while (j++ < g->winY)
	{
		i = -1;
		while (i++ < g->winX)
		{
			if (i == pos.x && j == pos.y)
			{
				while (y++ < to_place->height - 1)
				{
					x = -1;
					while (x++ < to_place->width)
						if (to_place->data[y * to_place->height + x] != -16777216)
						g->img->canvas->data[(j + y) * g->winY + (i + x)] =
							to_place->data[y * to_place->height + x];
				}
			}
		}
	}
}
