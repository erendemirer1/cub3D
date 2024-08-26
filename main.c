/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:39:43 by asoker            #+#    #+#             */
/*   Updated: 2024/08/24 17:26:27 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "minilibx/mlx.h"
#include <unistd.h>

static void	convert_rgb(t_color *color)
{
	color->color = (color->r << 16 | color->g << 8 | color->b);
	color->defined = true;
}

static int	keypress(int keycode, void *param)
{
	t_game	*key;

	key = (t_game *)param;
	if (keycode == 13)
		key->keys.w = true;
	if (keycode == 0)
		key->keys.a = true;
	if (keycode == 1)
		key->keys.s = true;
	if (keycode == 2)
		key->keys.d = true;
	if (keycode == 123)
		key->keys.left = true;
	if (keycode == 124)
		key->keys.right = true;
	if (keycode == 53)
		exitprogram(key, 1);
	return (0);
}

static int	keyrelease(int keyrls, void *param)
{
	t_game	*keys;

	keys = (t_game *)param;
	if (keyrls == 13)
		keys->keys.w = false;
	if (keyrls == 0)
		keys->keys.a = false;
	if (keyrls == 1)
		keys->keys.s = false;
	if (keyrls == 2)
		keys->keys.d = false;
	if (keyrls == 123)
		keys->keys.left = false;
	if (keyrls == 124)
		keys->keys.right = false;
	return (0);
}

static int	exitgame(void *games)
{
	t_game	*game;

	game = (t_game *)games;
	exitprogram(game, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		mapnameandfd(av[1], game.map.fd);
		game_init(&game, av[1]);
		mlx_initilazed(&game);
		initilazed_map(&game);
		game.img.img = mlx_new_image(game.mlx.mlx, W_WIDHT, W_HEIGHT);
		game.img.addr = (int *)mlx_get_data_addr(game.img.img,
				&game.img.bits_per_pixel,
				&game.img.line_lenght, &game.img.endian);
		convert_rgb(&game.map.floor_color);
		convert_rgb(&game.map.ceiling_color);
		mlx_hook(game.mlx.window, 2, 1L << 0, keypress, &game);
		mlx_hook(game.mlx.window, 3, 1L << 1, keyrelease, &game);
		mlx_loop_hook(game.mlx.mlx, gameloop, &game);
		mlx_hook(game.mlx.window, 17, 1L << 17, exitgame, &game);
		mlx_loop(game.mlx.mlx);
	}
	else
		write(2, "Error: Wrong arguments!!\n", 25);
}
