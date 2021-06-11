/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:36:19 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/11 19:40:05 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int
	key_pressed(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key_w = 1;
	if (keycode == 97)
		game->key_a = 1;
	if (keycode == 115)
		game->key_s = 1;
	if (keycode == 100)
		game->key_d = 1;
	return (0);
}

int
	key_released(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key_w = 0;
	if (keycode == 97)
		game->key_a = 0;
	if (keycode == 115)
		game->key_s = 0;
	if (keycode == 100)
		game->key_d = 0;
	return (0);
}
