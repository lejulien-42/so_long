/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:48 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 21:07:27 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void
	get_player_pos(t_game *game)
{
	int		i;
	int		j;

	j = -1;
	while (j++ < game->mapY - 1)
	{
		i = -1;
		while (i++ < game->mapX - 1)
		{
			if (game->map[j * game->mapX + i] == 'P')
			{
				game->player_pos = set_pos(i, j);
				return ;
			}
		}
	}
	game->player_pos = set_pos(-1, -1);
}
