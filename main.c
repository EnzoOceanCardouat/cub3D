/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:26:36 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/03 13:22:46 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

char **init_map(void)
{
	char **map;

	map = malloc(10 * sizeof(char *));
	map[0] = "1111111111111111";
	map[1] = "1000000000000001";
	map[2] = "1001110000010001";
	map[3] = "1000010011000101";
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
	mlx_window_create_info info = {0};

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
	game->ceiling = (mlx_color){.rgba = 0x448EE4FF};
	game->floor = (mlx_color){.rgba = 0x00C04BFF};
	init_player(&game->player, game);
	mlx_set_fps_goal(game->mlx, 30);
}

int	main()
{
	t_cube game;

	init_cube(&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYDOWN, key_hook, (void *)game.mlx);
	mlx_on_event(game.mlx, game.window, MLX_WINDOW_EVENT, window_hook, (void *)&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYDOWN, key_press, (void *)&game);
	mlx_on_event(game.mlx, game.window, MLX_KEYUP, key_release, (void *)&game);
	mlx_add_loop_hook(game.mlx, loop_game, &game);
	mlx_loop(game.mlx);
	freebox(&game);
}
