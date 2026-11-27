/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:36:27 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/27 11:11:35 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	p_close_to_door(t_cube *game, int m_y, int m_x)
{
	float	dx;
	float	dy;

	dx = game->player.x - (m_x + BLOCK / 2);
	dy = game->player.y - (m_y + BLOCK / 2);
	if (dx * dx + dy * dy < (BLOCK + BLOCK / 2) * (BLOCK + BLOCK / 2))
		return (true);
	else
		return (false);
}

bool	blocked(float x, float y, t_cube *game)
{
	if (touch(x - 4, y - 4, game))
		return (true);
	else if (touch(x + 4, y - 4, game))
		return (true);
	else if (touch(x - 4, y + 4, game))
		return (true);
	else if (touch(x + 4, y + 4, game))
		return (true);
	else
		return (false);
}

bool	touch(float rx, float ry, t_cube *game)
{
	int	x;
	int	y;

	x = rx / BLOCK;
	y = ry / BLOCK;
	if (x < 0 || y < 0 || x >= game->map_w || y >= game->map_h)
		return (true);
	if (game->map[y][x] == 'D')
	{
		if (p_close_to_door(game, y * BLOCK, x * BLOCK))
			return (false);
		else
			return (true);
	}
	if (game->map[y][x] == '1' || game->map[y][x] == ' ')
		return (true);
	else
		return (false);
}
