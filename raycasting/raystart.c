/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raystart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:05:11 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 11:04:56 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < W_WIDHT)
	{
		calc_ray_pos_dir(game, &ray, x);
		ray.map_x = (int)game->player.x;
		ray.map_y = (int)game->player.y;
		calc_ray_delta_dist(&ray);
		calc_ray_step_side_dist(game, &ray);
		perform_dda(game, &ray);
		calc_texture_width_height(game, &ray);
		calc_perp_wall_dist(&ray);
		calc_start_end_draw(&ray);
		calc_texture(game, &ray);
		draw_line(game, x, &ray);
		x++;
	}
}
