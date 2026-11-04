/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:44:39 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/04 10:56:00 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	ini_d_sqr(int *i, mlx_color *gray, mlx_color *lgry, mlx_color *door)
{
	*i = 0;
	*gray = (mlx_color){.rgba = 0x808080FF};
	*lgry = (mlx_color){.rgba = 0xD3D3D3FF};
	*door = (mlx_color){.rgba = 0xFFCE1BFF};
}

void	draw_square(int size, int color_switch, t_cube *game)
{
	int			i;
	int			j;
	mlx_color	gray;
	mlx_color	light_gray;
	mlx_color	door;

	ini_d_sqr(&i, &gray, &light_gray, &door);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (color_switch == -1)
				mlx_pixel_put(game->mlx, game->window, game->var.x + i,
					game->var.y + j, door);
			else if (color_switch % 2 == 1)
				mlx_pixel_put(game->mlx, game->window, game->var.x + i,
					game->var.y + j, gray);
			else
				mlx_pixel_put(game->mlx, game->window, game->var.x + i,
					game->var.y + j, light_gray);
			j++;
		}
		i++;
	}
}

int	get_tex_info(t_cube *game)
{
	float	prev_x;

	prev_x = game->var.ray_x - game->var.cos_angle;
	if ((int)(prev_x / BLOCK) != (int)(game->var.ray_x / BLOCK))
	{
		game->var.wall_x = fmodf(game->var.ray_y, BLOCK);
		if (game->var.cos_angle > 0)
			return (3);
		return (2);
	}
	game->var.wall_x = fmodf(game->var.ray_x, BLOCK);
	if (game->var.sin_angle > 0)
		return (0);
	return (1);
}

void	freebox(t_cube *game)
{
	if (game->map)
		free(game->map);
	if (game->textu[0])
		mlx_destroy_image(game->mlx, game->textu[0]);
	if (game->textu[1])
		mlx_destroy_image(game->mlx, game->textu[1]);
	if (game->textu[2])
		mlx_destroy_image(game->mlx, game->textu[2]);
	if (game->textu[3])
		mlx_destroy_image(game->mlx, game->textu[3]);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->image)
		mlx_destroy_image(game->mlx, game->image);
	if (game->mlx)
		mlx_destroy_context(game->mlx);
	exit(1);
}

double	get_dt(void)
{
	static struct timeval	last;
	struct timeval			now;
	double					dt;

	gettimeofday(&now, NULL);
	if (last.tv_sec == 0)
		last = now;
	dt = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) / 1e6;
	last = now;
	return (dt);
}
