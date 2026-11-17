/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:43:52 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 19:23:21 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"

char **init_map(void)
{
	char **map;

	map = malloc(10 * sizeof(char *));
	map[0] = "1111111111111111";
	map[1] = "1000000000000001";
	map[2] = "1001110000010001";
	map[3] = "10000D0011000101";
	map[4] = "1001110000010001";
	map[5] = "100000000011D111";
	map[6] = "100000N000000001";
	map[7] = "1000000000000001";
	map[8] = "1111111111111111";
	map[9] = NULL;
	return (map);
}

void	init_cube(t_cube *game)
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
	game->map = init_map(); //change
	load_texture(game);
	game->time = 0;
	game->ceiling = (mlx_color){.rgba = 0x090909FF}; //change
	game->floor = (mlx_color){.rgba = 0x222021FF}; //  change
	init_player(&game->player, game);
	mlx_set_fps_goal(game->mlx, 30);
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

	init_cube(&game);
	mlx_mouse_hide(game.mlx);
	mlx_mouse_move(game.mlx, game.window, WIDTH / 2, HEIGHT / 2);
	mlx_on_event(game.mlx, game.window, MLX_KEYDOWN, key_hook, (void *)game.mlx);
	mlx_on_event(game.mlx, game.window, MLX_WINDOW_EVENT, window_hook, (void *)&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYDOWN, key_press, (void *)&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYUP, key_release, (void *)&game);
	mlx_add_loop_hook(game.mlx, loop_game, &game);
	mlx_loop(game.mlx);
	freebox(&game);
	ft_exit(0, data);
}
