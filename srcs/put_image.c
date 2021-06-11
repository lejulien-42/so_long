/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:26:10 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/11 20:42:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void
	put_image(t_game *g, t_img_d *to_place, t_vec2 pos)
{
	int x;
	int y;

	y = -1;
	while (y++ < to_place->height - 1)
	{
		x = -1;
		while (x++ < to_place->width - 1)
			if (to_place->data[y * to_place->width + x] != -16777216)
				g->img->canvas->data[(pos.y + y) * g->winX + (pos.x + x)] =
					to_place->data[y * to_place->width + x];
	}
}
