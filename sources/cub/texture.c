/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:37:34 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/11 14:42:56 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	load_texture(t_cube *game)
{
	const char	*wall_path[] = {"texture/Moon.png", "texture/Mars.png",
		"texture/Jupiter.png", "texture/Neptune.png"};
	const char	*door_path = "texture/BlackHole.png";
	const char	*ufo_path[] = {"texture/0.png", "texture/1.png", "texture/2.png",
		"texture/3.png", "texture/4.png", "texture/5.png", "texture/6.png",
		"texture/7.png", "texture/8.png","texture/9.png", "texture/10.png",
		"texture/11.png", "texture/12.png","texture/13.png","texture/14.png",
		"texture/15.png", "texture/16.png", "texture/17.png", "texture/18.png",
		"texture/19.png","texture/19.png","texture/20.png","texture/21.png",
		"texture/22.png","texture/23.png","texture/24.png","texture/25.png",
		"texture/26.png","texture/27.png","texture/28.png", "texture/28.png"};
	int		i;

	i = 0;
	while (i < 4)
	{
		game->textu[i] = mlx_new_image_from_file(game->mlx, wall_path[i],
				&game->texture_width, &game->texture_height);
		if (!game->textu[i])
			freebox(game);
		i++;
	}
	i = 0;
	while (i < 30)
	{
		game->ufo[i] = mlx_new_image_from_file(game->mlx, ufo_path[i],
				&game->ufo_width, &game->ufo_height);
		if (!game->ufo[i])
			freebox(game);
		i++;
	}
	game->door = mlx_new_image_from_file(game->mlx, door_path,
			&game->texture_width, &game->texture_height);
	if (!game->door)
		freebox(game);
}

void	render_texture(t_cube *game, int i)
{
	game->var.c = 0;
	while (game->var.c < game->var.y)
	{
		mlx_pixel_put(game->mlx, game->window, i, game->var.c, game->ceiling);
		game->var.c++;
	}
	while (game->var.y < game->var.end)
	{
		game->var.tex_y = (int)((game->var.y - game->var.top)
				* game->texture_height / game->var.height);
		if (game->var.tex_y >= game->texture_height)
			game->var.tex_y = game->texture_height - 1;
		if (game->map[game->var.m_y][game->var.m_x] == 'D')
			game->wall = mlx_get_image_pixel(game->mlx, game->door,
					game->var.tex_x, game->var.tex_y);
		else
			game->wall = mlx_get_image_pixel(game->mlx,
					game->textu[game->var.t], game->var.tex_x, game->var.tex_y);
		mlx_pixel_put(game->mlx, game->window, i, game->var.y, game->wall);
		game->var.y++;
	}
	while (game->var.end < HEIGHT)
		mlx_pixel_put(game->mlx, game->window, i, game->var.end++, game->floor);
}

void	texture_orientation(t_cube *game)
{
	if (game->var.tex_x >= game->texture_width)
		game->var.tex_x = game->texture_width - 1;
	if (game->var.top < 0)
		game->var.y = 0;
	else
		game->var.y = (int)game->var.top;
	if (game->var.top + game->var.height > HEIGHT)
		game->var.end = HEIGHT;
	else
		game->var.end = (int)(game->var.top + game->var.height);
}
