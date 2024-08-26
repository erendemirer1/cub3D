/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:13:44 by asoker            #+#    #+#             */
/*   Updated: 2024/08/20 03:48:56 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

static void	player_movement(t_game *game)
{
	player_x(game);
	player_y(game);
}

int	gameloop(t_game *game)
{
	player_movement(game);
	player_rotation(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->img.img, 0, 0);
	return (0);
}
