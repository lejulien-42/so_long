/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:26:10 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/09 19:41:18 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void
	put_image(void *img, t_game *game, int x, int y)
{
	int		poubelle;
	char	*data;
	data = mlx_get_data_addr(game->img->mouse_img, &poubelle, &poubelle, &poubelle);
	printf("%s\n", data);
}
