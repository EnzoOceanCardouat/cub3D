/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:43:52 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/18 14:45:46 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"


static void	init_texture(t_cube *game, t_info_data *data)
{
	game->ceiling = data->ceiling_color;
	game->floor = data->floor_color;
	game->north_texture = data->north_texture;
	game->south_texture = data->south_texture;
	game->west_texture = data->west_texture;
	game->east_texture = data->east_texture;
	game->door_texture = data->door_texture;
}

static void	init_cube(t_cube *game, t_info_data *data)
{
	mlx_window_create_info	info = {0};

	info.title = "Cub3D";
	info.height = HEIGHT;
	info.width = WIDTH;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->window = mlx_new_window(game->mlx, &info);
	if (!game->window)
		freebox(game);
	game->image = mlx_new_image(game->mlx, (int)WIDTH, (int)HEIGHT);
	if (!game->image)
		freebox(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	game->map = data->map;
	game->time = 0;
	init_texture(game, data);
	init_player(&game->player, game);
	load_texture(game);
	mlx_set_fps_goal(game->mlx, 30);
	game->data = data;
	game->var.g = 0;
}

int	main(int ac, char **av)
{
	t_cube game;
	t_info_data	*data;

	if (ac != 2)
		return (1);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (1);
	data = ft_calloc(1, sizeof(t_info_data));
	if (!data)
		return (1);
	parsing(av[1], data);
	ft_bzero(&game, sizeof(game));
	init_cube(&game, data);
	mlx_mouse_hide(game.mlx);
	mlx_mouse_move(game.mlx, game.window, WIDTH / 2, HEIGHT / 2);
	mlx_on_event(game.mlx, game.window, MLX_KEYDOWN, key_hook, (void *)game.mlx);
	mlx_on_event(game.mlx, game.window, MLX_WINDOW_EVENT, window_hook, (void *)&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYDOWN, key_press, (void *)&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYUP, key_release, (void *)&game);
	mlx_add_loop_hook(game.mlx, loop_game, &game);
	mlx_loop(game.mlx);
	freebox(&game);
}
