/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:37:35 by asoker            #+#    #+#             */
/*   Updated: 2024/08/24 18:12:51 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "minilibx/mlx.h"
#include "libft/utils.h"
#include <unistd.h>

void	mlx_initilazed(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		write(2, "Error: Mlx initilazed problem !!\n", 33);
		exitfunc(game, 2);
	}
	game->mlx.window = mlx_new_window(game->mlx.mlx, W_WIDHT,
			W_HEIGHT, "cub3D");
	if (!game->mlx.window)
	{
		write(2, "Error: Mlx new window initalize problem !!\n", 43);
		exitfunc(game, 2);
	}
}

static void	player_init(t_game *game)
{
	game->player.x = -1;
	game->player.y = -1;
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.direction = 0;
	game->player.rot_speed = 0.04;
	game->player.move_speed = 0.1;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0;
}

static void	map_init(t_game *game, char *map)
{
	game->map.path = ft_strdup(map);
	if (!game->map.path)
		return (exitfunc(game, 1));
	game->map.lines = 0;
	game->map.map = 0;
	game->map.height = 0;
	game->map.tmp_map = 0;
	game->map.wall.no_texture.path = 0;
	game->map.wall.so_texture.path = 0;
	game->map.wall.we_texture.path = 0;
	game->map.wall.ea_texture.path = 0;
	game->map.wall.no_texture.img = 0;
	game->map.wall.so_texture.img = 0;
	game->map.wall.we_texture.img = 0;
	game->map.wall.ea_texture.img = 0;
	game->map.wall.no_texture.width = 0;
	game->map.wall.so_texture.width = 0;
	game->map.wall.we_texture.width = 0;
	game->map.wall.ea_texture.width = 0;
	game->map.wall.no_texture.height = 0;
	game->map.wall.so_texture.height = 0;
	game->map.wall.we_texture.height = 0;
	game->map.wall.ea_texture.height = 0;
	game->map.floor_color.defined = false;
	game->map.ceiling_color.defined = false;
}

void	game_init(t_game *game, char *map)
{
	player_init(game);
	map_init(game, map);
}
