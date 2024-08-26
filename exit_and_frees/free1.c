/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:48:33 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 11:16:00 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

void	exitfunc2(t_game *game, int def)
{
	if (def == 2)
	{
		write (2, "Error: WALLS NOT CLOSED\n", 24);
		exitprogram(game, 2);
	}
	if (def == 3)
	{
		write (2, "Error: There is more than 1 Player\n", 35);
		exitprogram(game, 2);
	}
	if (def == 4)
	{
		write (2, "Error: Invalid char !\n", 22);
		exitprogram(game, 2);
	}
	if (def == 5)
	{
		write (2, "Error: N,S,W,E,F,C !!\n", 22);
		exitprogram(game, 2);
	}
}

static void	destroy(t_game *game)
{
	if (game->map.wall.no_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.no_texture.img);
	if (game->map.wall.so_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.so_texture.img);
	if (game->map.wall.we_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.we_texture.img);
	if (game->map.wall.ea_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.ea_texture.img);
	mlx_destroy_window(game->mlx.mlx, game->mlx.window);
	free(game->mlx.mlx);
}

static void	pathdestroy(t_game *game)
{
	if (game->map.wall.no_texture.path)
		free(game->map.wall.no_texture.path);
	if (game->map.wall.so_texture.path)
		free(game->map.wall.so_texture.path);
	if (game->map.wall.we_texture.path)
		free(game->map.wall.we_texture.path);
	if (game->map.wall.ea_texture.path)
		free(game->map.wall.ea_texture.path);
}

void	exitprogram(t_game *game, int status)
{
	if (status == 1 || status == 2)
	{
		destroy(game);
		pathdestroy(game);
		if (game->map.fd)
			close(game->map.fd);
		if (game->map.path)
			free(game->map.path);
		if (game->map.map)
			freesplit(game->map.map);
		if (game->map.tmp_map)
			freesplit(game->map.tmp_map);
		if (game->map.lines)
			freesplit(game->map.lines);
	}
	if (status == 2)
		exit(1);
	write (1, "\x1b[32mProgram is closed.\x1b[0m\n", 29);
	exit(0);
}

void	exitfunc(t_game *game, int status)
{
	if (status == 1)
	{
		write(2, "Error: malloc error !! \n", 24);
		exit (1);
	}
	else if (status == 2)
	{
		if (game->map.fd)
			close(game->map.fd);
		if (game->map.path)
			free(game->map.path);
		if (game->map.map)
			freesplit(game->map.map);
		if (game->map.lines)
			freesplit(game->map.lines);
		if (game->map.tmp_map)
			freesplit(game->map.tmp_map);
		if (game->mlx.mlx)
		{
			if (game->mlx.window)
				mlx_destroy_window(game->mlx.mlx, game->mlx.window);
			free(game->mlx.mlx);
		}
		exit(1);
	}
}
