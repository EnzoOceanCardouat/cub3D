/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:34:54 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/04 10:36:01 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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

void	init_player(t_player *player, t_cube *game)
{
	init_pos_player(player, game);
	if (player->spawn_direction == 'N')
		player->angle = (3 * M_PI / 2);
	else if (player->spawn_direction == 'S')
		player->angle = (M_PI / 2);
	else if (player->spawn_direction == 'W')
		player->angle = M_PI;
	else if (player->spawn_direction == 'E')
		player->angle = 0;
	player->w = false;
	player->s = false;
	player->a = false;
	player->d = false;
	player->left = false;
	player->right = false;
	player->spawn = false;
	player->m = false;
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

void	move_player(t_player *player, t_cube game)
{
	double	dt;

	dt = get_dt();
	player->var.speed = 50 * dt;
	player->var.angle_speed = 2 * dt;
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
