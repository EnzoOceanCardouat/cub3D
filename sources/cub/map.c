/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:32:46 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/04 10:46:56 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	draw_player_mini_map(t_cube *game)
{
	const char	*template[] = {"0001000", "0001000", "0011100", "0011100",
		"0111110", "0111110", "1111111", "1111111", "1110111", "0100010"};
	int			map_size;
	int			origin_x;
	int			origin_y;

	map_size = BLOCK / 2;
	origin_x = 50 + (game->player.x * map_size) / BLOCK - 7 / 2;
	origin_y = 50 + (game->player.y * map_size) / BLOCK - 10 / 2;
	game->var.i = 0;
	while (game->var.i < 10)
	{
		game->var.j = 0;
		while (game->var.j < 7)
		{
			if (template[game->var.i][game->var.j] == '1')
				mlx_pixel_put(game->mlx, game->window, origin_x + game->var.j,
					origin_y + game->var.i, (mlx_color){.rgba = 0xFF1493FF});
			game->var.j++;
		}
		game->var.i++;
	}
}

void	draw_mini_map(t_cube *game)
{
	int	size;

	game->var.y = 50;
	game->var.i = 0;
	size = BLOCK / 2;
	while (game->map[game->var.i])
	{
		game->var.x = 50;
		game->var.j = 0;
		while (game->map[game->var.i][game->var.j])
		{
			if (game->map[game->var.i][game->var.j] == '1')
				draw_square(size, game->var.j + game->var.i, game);
			else if (game->map[game->var.i][game->var.j] == 'D')
				draw_square(size, -1, game);
			game->var.x += size;
			game->var.j++;
		}
		game->var.y += size;
		game->var.i++;
	}
	draw_player_mini_map(game);
}
