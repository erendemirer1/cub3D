/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:08:35 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 12:49:25 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>

# define W_WIDHT 1920
# define W_HEIGHT 1080

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				color;
	bool			defined;
}	t_color;

typedef struct s_image
{
	char	*path;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_wall
{
	t_image		no_texture;
	t_image		so_texture;
	t_image		we_texture;
	t_image		ea_texture;
}	t_wall;

typedef struct s_map
{
	char	*path;
	int		fd;
	char	**lines;
	char	**map;
	char	**tmp_map;
	int		height;
	t_wall	wall;
	t_color	floor_color;
	t_color	ceiling_color;
}	t_map;
typedef struct s_keys
{
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		right;
	bool		left;
}	t_keys;

typedef struct s_texture
{
	double	pos;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_texture;

typedef struct s_ray
{
	double		camera_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		ray_dir_x;
	double		ray_dir_y;
	double		wall_x;
	double		step;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			floor;
	int			ceiling;
	int			draw_start;
	int			draw_end;
	t_texture	texture;
	t_texture	current_texture;
}			t_ray;

typedef struct s_player
{
	enum e_direction	direction;
	double				move_speed;
	double				x;
	double				y;
	double				rot_speed;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_game
{
	t_image		img;
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_keys		keys;
}	t_game;

/* error and exit functions */
void	freesplit(char **split);
void	exitfunc(t_game *game, int status);
void	exitprogram(t_game *game, int status);
void	exitfunc2(t_game *game, int def);

/* map control functions */;
void	map_checker(t_game *game);
int		ft_pathfinder(char **map, int height, int x, int y);
void	mapnameandfd(char *map, int fd);
int		settlement_map(t_game *game);
void	initilazed_map(t_game *game);
void	pass_spaces(t_game *game, int i, int j);
void	map_line(t_game *game, int y);
void	total_height_map(t_game *game);
void	copy_map(t_game *game);
int		control_map_char(char c);
void	zerocontrol(t_game *game, char **map, int i, int j);
/* game initilazed */
void	game_init(t_game *game, char *map);
/* mlx functions */
void	mlx_initilazed(t_game *game);
/* color and texture */
int		set_texture(t_game *game, t_image *image, char *path);
int		set_color(t_color *color, t_game *game, char *split);

/* player movement and rotation */
void	player_x(t_game *game);
void	player_y(t_game *game);
void	player_rotation(t_game *game);
int		gameloop(t_game *game);

/* raycasting algorithms and dda*/

void	calc_ray_pos_dir(t_game *game, t_ray *ray, int x);
void	calc_ray_delta_dist(t_ray *ray);
void	calc_ray_step_side_dist(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calc_texture(t_game *game, t_ray *ray);
void	calc_texture_width_height(t_game *game, t_ray *ray);
void	calc_perp_wall_dist(t_ray *ray);
void	calc_start_end_draw(t_ray *ray);
void	draw_line(t_game *game, int x, t_ray *ray);
void	raycasting(t_game *game);

#endif