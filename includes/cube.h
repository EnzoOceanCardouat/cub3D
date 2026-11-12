/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:57:16 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/12 11:12:05 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libs/MacroLibX/includes/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <sys/time.h>

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 24
# define W 26
# define A 4
# define S 22
# define D 7
# define LEFT 80
# define RIGHT 79
# define M 16
# define TXT_WIDTH 80
# define TXT_HEIGHT 80
# define MOUSE_SENS 0.0005

typedef struct s_var
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		m_x;
	int		m_y;
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	int		t;
	float	dist;
	float	height;
	float	top;
	float	wall_x;
	int		c;
	int		tex_x;
	int		tex_y;
	int		end;
	float	speed;
	float	angle_speed;
	int		new_x;
	int		new_y;
	int		g;
}	t_var;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	char	spawn_direction;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	spawn;
	bool	m;
	t_var	var;
}	t_player;

typedef struct s_cube
{
	void		*mlx;
	void		*window;
	void		*image;
	t_player	player;
	char		**map;
	mlx_image	textu[4];
	mlx_image	door;
	mlx_image	ufo[30];
	int			texture_width;
	int			texture_height;
	int			ufo_width;
	int			ufo_height;
	int			time;
	mlx_color	ceiling;
	mlx_color	floor;
	mlx_color	wall;
	t_var		var;
}	t_cube;

/* hook.c */
void	window_hook(int key, void *param);
void	key_hook(int key, void *param);
void	key_press(int key, void *_player);
void	key_release(int key, void *_player);

/* utils.c */
void	draw_square(int size, int color_switch, t_cube *game);
int		get_tex_info(t_cube *game);
void	freebox(t_cube *game);
double	get_dt(void);

/* player.c */
void	init_player(t_player *player, t_cube *game);
void	move_player(t_player *player, t_cube game);

/* rayCasting.c */
bool	touch(float px, float py, t_cube *game);
bool	p_close_to_door(t_cube *game, int m_y, int m_x);

/* main.c */
void	draw_mini_map(t_cube *game);

/* texture.c */
void	load_texture(t_cube *game);
void	render_texture(t_cube *game, int i);
void	texture_orientation(t_cube *game);

/* map.c */
void	draw_mini_map(t_cube *game);

/* game.c */
void	loop_game(void *_game);

#endif
