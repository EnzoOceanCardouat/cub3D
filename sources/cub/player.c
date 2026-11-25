/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:34:54 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/25 16:45:06 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_pos_player(t_player *player, t_cube *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
					|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				player->x = ((j * BLOCK) + BLOCK) - BLOCK / 2;
				player->y = ((i * BLOCK) + BLOCK) - BLOCK / 2;
				player->spawn_direction = game->map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	w_s_move(t_player *plyr, t_cube *game)
{
	if (plyr->w)
	{
		plyr->var.new_x = plyr->x + plyr->var.cos_angle * plyr->var.speed;
		plyr->var.new_y = plyr->y + plyr->var.sin_angle * plyr->var.speed;
		if (!touch(plyr->var.new_x, plyr->var.new_y, game))
		{
			plyr->x = plyr->var.new_x;
			plyr->y = plyr->var.new_y;
		}
	}
	if (plyr->s)
	{
		plyr->var.new_x = plyr->x - plyr->var.cos_angle * plyr->var.speed;
		plyr->var.new_y = plyr->y - plyr->var.sin_angle * plyr->var.speed;
		if (!touch(plyr->var.new_x, plyr->var.new_y, game))
		{
			plyr->x = plyr->var.new_x;
			plyr->y = plyr->var.new_y;
		}
	}
}

void	a_d_move(t_player *plyr, t_cube *game)
{
	if (plyr->d)
	{
		plyr->var.new_x = plyr->x - plyr->var.sin_angle * plyr->var.speed;
		plyr->var.new_y = plyr->y + plyr->var.cos_angle * plyr->var.speed;
		if (!touch(plyr->var.new_x, plyr->var.new_y, game))
		{
			plyr->x = plyr->var.new_x;
			plyr->y = plyr->var.new_y;
		}
	}
	if (plyr->a)
	{
		plyr->var.new_x = plyr->x + plyr->var.sin_angle * plyr->var.speed;
		plyr->var.new_y = plyr->y - plyr->var.cos_angle * plyr->var.speed;
		if (!touch(plyr->var.new_x, plyr->var.new_y, game))
		{
			plyr->x = plyr->var.new_x;
			plyr->y = plyr->var.new_y;
		}
	}
}

void	is_focus(t_player *player, t_cube game, int *mx, int *my)
{
	if (!game.focus)
		(void)mx;
	if (!game.focus)
		(void)my;
	if (game.focus)
	{
		mlx_mouse_get_pos(game.mlx, mx, my);
		player->angle += (*mx - WIDTH / 2) * MOUSE_SENS;
		mlx_mouse_move(game.mlx, game.window, WIDTH / 2, HEIGHT / 2);
	}
}

void	move_player(t_player *player, t_cube game)
{
	double	dt;
	int		mx;
	int		my;

	dt = get_dt();
	player->var.speed = 50 * dt;
	player->var.angle_speed = 2 * dt;
	is_focus(player, game, &mx, &my);
	if (player->left)
		player->angle -= player->var.angle_speed;
	if (player->right)
		player->angle += player->var.angle_speed;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	else if (player->angle < 0)
		player->angle += 2 * M_PI;
	player->var.cos_angle = cos(player->angle);
	player->var.sin_angle = sin(player->angle);
	w_s_move(player, &game);
	a_d_move(player, &game);
}
