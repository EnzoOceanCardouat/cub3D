/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:32:24 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/04 10:32:38 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end((mlx_context)param);
}

void	window_hook(int key, void *param)
{
	if (key == 0)
		mlx_loop_end((mlx_context)param);
}

void	key_press(int key, void *_player)
{
	t_player	*player;

	player = &((t_cube *)_player)->player;
	if (key == W)
		player->w = true;
	else if (key == S)
		player->s = true;
	else if (key == A)
		player->a = true;
	else if (key == D)
		player->d = true;
	else if (key == LEFT)
		player->left = true;
	else if (key == RIGHT)
		player->right = true;
	else if (key == M)
	{
		if (!player->m)
			player->m = true;
		else
			player->m = false;
	}
}

void	key_release(int key, void *_player)
{
	t_player	*player;

	player = &((t_cube *)_player)->player;
	if (key == W)
		player->w = false;
	else if (key == S)
		player->s = false;
	else if (key == A)
		player->a = false;
	else if (key == D)
		player->d = false;
	else if (key == LEFT)
		player->left = false;
	else if (key == RIGHT)
		player->right = false;
}
