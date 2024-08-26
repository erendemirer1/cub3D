/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:12:47 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 12:50:02 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/utils.h"
#include <unistd.h>

static enum e_direction	get_direction(char c)
{
	if (c == 'W')
		return (WEST);
	else if (c == 'N')
		return (NORTH);
	else if (c == 'E')
		return (EAST);
	else if (c == 'S')
		return (SOUTH);
	return (0);
}

static void	modify_direction2(t_game *game, enum e_direction direction)
{
	if (direction == WEST)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	else if (direction == EAST)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

static void	modify_direction(t_game *game, char c)
{
	enum e_direction	direction;

	direction = get_direction(c);
	game->player.direction = direction;
	if (direction == NORTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == SOUTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	modify_direction2(game, direction);
}

static void	map_checker2(t_game *game, char **map, int i, int j)
{
	if (i == 0 || i == game->map.height - 1 || j == 0
		|| j == ft_strlen(map[i]) - 2)
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\n')
			exitfunc2(game, 2);
	if (map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'W'
		|| map[i][j] == 'N')
	{
		if (game->player.x != -1 || game->player.y != -1)
		{
			exitfunc2(game, 3);
		}
		modify_direction(game, map[i][j]);
		game->player.x = j + 0.5;
		game->player.y = i + 0.5;
	}
	if (!control_map_char(map[i][j]))
		exitfunc2(game, 4);
}

void	map_checker(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	tmp_map = game->map.map;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			map_checker2(game, tmp_map, i, j);
			if (tmp_map[i][j] == '0')
				zerocontrol(game, tmp_map, i, j);
			j++;
		}
		i++;
	}
	if (game->player.x == -1 || game->player.y == -1)
	{
		write(2, "Error: There is no player on the map !\n", 39);
		exitprogram(game, 2);
	}
}
