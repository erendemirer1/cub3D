/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:53:21 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 11:35:02 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/utils.h"

static int	get_longest_line(char **map)
{
	int	i;
	int	longest_line;

	i = 0;
	longest_line = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > longest_line)
			longest_line = ft_strlen(map[i]);
		i++;
	}
	return (longest_line);
}

void	copy_map(t_game *game)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	line_len = get_longest_line(game->map.map);
	game->map.tmp_map = (char **)ft_calloc(game->map.height + 1,
			sizeof(char *));
	if (!game->map.tmp_map)
		exitprogram(game, 2);
	while (game->map.map[i])
	{
		j = 0;
		game->map.tmp_map[i] = (char *)ft_calloc(line_len + 1, sizeof(char));
		if (!game->map.tmp_map[i])
			exitprogram(game, 2);
		while (game->map.map[i][j])
		{
			game->map.tmp_map[i][j] = game->map.map[i][j];
			j++;
		}
		game->map.tmp_map[i][j] = '\0';
		i++;
	}
	game->map.tmp_map[i] = NULL;
}

static void	set_six_values(t_game *game, int *count, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
		*count += set_texture(game, &game->map.wall.no_texture, split[1]);
	else if (!ft_strcmp(split[0], "SO"))
		*count += set_texture(game, &game->map.wall.so_texture, split[1]);
	else if (!ft_strcmp(split[0], "WE"))
		*count += set_texture(game, &game->map.wall.we_texture, split[1]);
	else if (!ft_strcmp(split[0], "EA"))
		*count += set_texture(game, &game->map.wall.ea_texture, split[1]);
	else if (!ft_strcmp(split[0], "F"))
		*count += set_color(&game->map.floor_color, game, split[1]);
	else if (!ft_strcmp(split[0], "C"))
		*count += set_color(&game->map.ceiling_color, game, split[1]);
}

void	pass_spaces(t_game *game, int i, int j)
{
	while (game->map.lines[i])
	{
		j = 0;
		while (game->map.lines[i][j] == ' ' || game->map.lines[i][j] == '\t' ||
			game->map.lines[i][j] == '\n' || game->map.lines[i][j] == '\v' ||
			game->map.lines[i][j] == '\f' || game->map.lines[i][j] == '\r')
			j++;
		if (game->map.lines[i][j] != '\0')
			break ;
		i++;
	}
	j = 0;
	game->map.map = ft_calloc(game->map.height - i + 1, sizeof(char *));
	if (!game->map.map)
		exitprogram(game, 2);
	while (game->map.lines[i])
	{
		game->map.map[j] = ft_strdup(game->map.lines[i]);
		if (!game->map.map[j])
			exitprogram(game, 2);
		i++;
		j++;
	}
	game->map.map[j] = NULL;
	game->map.height = j;
}

int	settlement_map(t_game *game)
{
	int		i;
	char	**parse;
	int		sixcount;

	i = 0;
	sixcount = 0;
	while (game->map.lines[i])
	{
		parse = ft_split(game->map.lines[i], ' ');
		if (!parse)
			exitfunc(game, 2);
		set_six_values(game, &sixcount, parse);
		freesplit(parse);
		i++;
		if (sixcount == 6)
			break ;
	}
	if (sixcount != 6)
		exitfunc2(game, 5);
	return (i);
}
