/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:36:27 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/04 10:37:25 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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

bool	touch(float px, float py, t_cube *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (x >= WIDTH / BLOCK || y >= HEIGHT / BLOCK || x < 0 || y < 0)
		return (true);
	if (game->map[y][x] == 'D')
	{
		if (p_close_to_door(game, y * BLOCK, x * BLOCK))
			return (false);
		else
			return (true);
	}
	if (game->map[y][x] == '1')
		return (true);
	else
		return (false);
}
