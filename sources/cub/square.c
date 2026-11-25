/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 11:08:58 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/25 10:59:59 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
