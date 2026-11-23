/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:44:39 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/23 11:08:46 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"

void	freebox(t_cube *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textu[i])
			mlx_destroy_image(game->mlx, game->textu[i]);
		i++;
	}
	i = 0;
	while (i < 30)
	{
		if (game->ufo[i])
			mlx_destroy_image(game->mlx, game->ufo[i]);
		i++;
	}
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->image)
		mlx_destroy_image(game->mlx, game->image);
	if (game->mlx)
		mlx_destroy_context(game->mlx);
	ft_exit(0, game->data);
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

bool	file_exists(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
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
