/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:13:46 by asoker            #+#    #+#             */
/*   Updated: 2024/08/20 03:33:07 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

void	player_x(t_game *game)
{
	if (game->keys.a)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
				- game->player.plane_x * game->player.move_speed)] != '1')
			game->player.x -= game->player.plane_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y - game->player.plane_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y -= game->player.plane_y * game->player.move_speed;
	}
	if (game->keys.d)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
				+ game->player.plane_x * game->player.move_speed)] != '1')
			game->player.x += game->player.plane_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y + game->player.plane_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y += game->player.plane_y * game->player.move_speed;
	}
}

void	player_y(t_game *game)
{
	if (game->keys.w)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
			+ game->player.dir_x * game->player.move_speed)] != '1')
			game->player.x += game->player.dir_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y + game->player.dir_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y += game->player.dir_y * game->player.move_speed;
	}
	if (game->keys.s)
	{
		if (game->map.map[(int)(game->player.y)][(int)(game->player.x
			- game->player.dir_x * game->player.move_speed)] != '1')
			game->player.x -= game->player.dir_x * game->player.move_speed;
		if (game->map.map[(int)(game->player.y - game->player.dir_y
				* game->player.move_speed)][(int)(game->player.x)] != '1')
			game->player.y -= game->player.dir_y * game->player.move_speed;
	}
}
