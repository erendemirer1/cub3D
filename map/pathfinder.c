/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:19:34 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 12:50:59 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/utils.h"

void	zerocontrol(t_game *game, char **map, int i, int j)
{
	if (i == 0 || i == game->map.height - 1 || j == 0
		|| j == ft_strlen(map[i]) - 2)
		exitfunc2(game, 2);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		exitfunc2(game, 2);
	else if (map[i - 1][j] == '\0' || map[i + 1][j] == '\0'
		|| map[i][j - 1] == '\0' || map[i][j + 1] == '\0')
		exitfunc2(game, 2);
}

int	ft_pathfinder(char **map, int height, int x, int y)
{
	int	total;

	total = 0;
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == '\0' || map[y][x] == '\n' || map[y][x] == ' ')
		return (1);
	map[y][x] = '1';
	if (map[y][x + 1])
		total += ft_pathfinder(map, height, x + 1, y);
	if (x - 1 >= 0)
		total += ft_pathfinder(map, height, x - 1, y);
	if (y + 1 < height)
		total += ft_pathfinder(map, height, x, y + 1);
	if (y - 1 >= 0)
		total += ft_pathfinder(map, height, x, y - 1);
	if (total > 0)
		return (1);
	return (0);
}
