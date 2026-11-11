/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:14:08 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/11 15:20:43 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static float	distance(float x, float y)
{
	float	sq;

	sq = sqrt(x * x + y * y);
	return (sq);
}

static float	fix_distance(float x1, float y1, t_cube *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = game->var.ray_x - x1;
	delta_y = game->var.ray_y - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

static void	render_3d(t_player *player, t_cube *game, float start_x, int i)
{
	game->var.cos_angle = cos(start_x);
	game->var.sin_angle = sin(start_x);
	game->var.ray_x = player->x;
	game->var.ray_y = player->y;
	while (!touch(game->var.ray_x, game->var.ray_y, game))
	{
		game->var.ray_x += game->var.cos_angle;
		game->var.ray_y += game->var.sin_angle;
	}
	game->var.dist = fix_distance(player->x, player->y, game);
	game->var.height = (BLOCK / game->var.dist) * (WIDTH / 2);
	game->var.top = (HEIGHT - game->var.height) / 2;
	game->var.m_x = (int)(game->var.ray_x / BLOCK);
	game->var.m_y = (int)(game->var.ray_y / BLOCK);
	game->var.t = get_tex_info(game);
	game->var.tex_x = (int)(game->var.wall_x / BLOCK * game->texture_width);
	texture_orientation(game);
	render_texture(game, i);
}

void	loop_game(void *_game)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = M_PI / 3 / WIDTH;
	start_x = ((t_cube *)_game)->player.angle - M_PI / 6;
	i = 0;
	move_player(&((t_cube *)_game)->player, *(t_cube *)_game);
	mlx_clear_window(((t_cube *)_game)->mlx, ((t_cube *)_game)->window,
		(mlx_color){.rgba = 0x00000000});
	while (i < WIDTH)
	{
		render_3d(&((t_cube *)_game)->player, (t_cube *)_game, start_x, i);
		start_x += fraction;
		i++;
	}
	if (((t_cube *)_game)->player.m == true)
		draw_mini_map((t_cube *)_game);
	if (((t_cube *)_game)->player.w || ((t_cube *)_game)->player.s || ((t_cube *)_game)->player.a || ((t_cube *)_game)->player.d)
	{
		((t_cube *)_game)->time++;
		if (((t_cube *)_game)->time % 1 == 0)
			((t_cube *)_game)->var.g = (((t_cube *)_game)->var.g + 1) % 30;
		mlx_put_image_to_window(((t_cube *)_game)->mlx, ((t_cube *)_game)->window, ((t_cube *)_game)->ufo[((t_cube *)_game)->var.g], 0, 0);
	}
	else
		mlx_put_image_to_window(((t_cube *)_game)->mlx, ((t_cube *)_game)->window, ((t_cube *)_game)->ufo[((t_cube *)_game)->var.g], 0, 0);
}
