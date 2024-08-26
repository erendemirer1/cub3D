/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:45:35 by asoker            #+#    #+#             */
/*   Updated: 2024/08/24 18:31:14 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include "../libft/utils.h"

int	control_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == '\n')
		return (1);
	else
		return (0);
}

void	mapnameandfd(char *map, int fd)
{
	int	i;

	i = ft_strlen(map);
	if ((map[i - 1] != 'b' || map[i - 2] != 'u' || map[i - 3] != 'c'
			|| map[i - 4] != '.'))
	{
		write(2, "Error: MAPNAME !!", 17);
		exit(1);
	}
	fd = open(map, O_RDONLY);
	if (fd <= 0)
	{
		write(2, "Error: MAP FD !!", 16);
		exit(1);
	}
	close(fd);
}

void	total_height_map(t_game *game)
{
	char	*line;
	int		height;

	height = 0;
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
	{
		write(2, "Error: FD OPEN READ PROBLEM !!\n", 31);
		exitfunc(game, 2);
	}
	line = get_next_line(game->map.fd);
	if (!line)
		exitfunc(game, 2);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
	game->map.height = height;
}

void	map_line(t_game *game, int y)
{
	char	*line;

	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
	{
		write(2, "Error :FD OPEN READ PROBLEM !!\n", 31);
		exitfunc(game, 2);
	}
	game->map.lines = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!(game->map.lines))
		exitfunc(game, 2);
	line = get_next_line(game->map.fd);
	if (!line)
		exitfunc(game, 2);
	while (line)
	{
		game->map.lines[y] = ft_strdup(line);
		if (!game->map.lines[y])
			exitfunc(game, 2);
		free(line);
		line = get_next_line(game->map.fd);
		y++;
	}
	close(game->map.fd);
}

void	initilazed_map(t_game *game)
{
	int	i;

	i = 0;
	total_height_map(game);
	map_line(game, 0);
	i = settlement_map(game);
	pass_spaces(game, i, 0);
	map_checker(game);
	copy_map(game);
	i = ft_pathfinder(game->map.tmp_map, game->map.height, (int)game->player.x,
			(int)game->player.y);
	if (i > 0)
	{
		write(2, "Error: There is a problem pathfinder !\n", 39);
		exitprogram(game, 2);
	}
}
