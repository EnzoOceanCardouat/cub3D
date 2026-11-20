/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:55:58 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/18 16:37:44 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

/**
 * @brief If the current index in the array is a player (N,S,W,E) and
 * no players are registered, the data register this user.
 * In case of a user which is already registred, trigger an error.
 *
 * @param data The structure of all the parsing system.
 * @param i The columns index.
 * @param j The row index.
 */
int	check_player(t_info_data *data, int i, int j)
{
	if ((data->space_map[i][j] == 'N' || data->space_map[i][j] == 'S'
		|| data->space_map[i][j] == 'E' || data->space_map[i][j] == 'W')
			&& !data->player)
		data->player = data->space_map[i][j];
	else if ((data->space_map[i][j] == 'N' || data->space_map[i][j] == 'S'
		|| data->space_map[i][j] == 'E' || data->space_map[i][j] == 'W')
			&& data->player)
	{
		printf("Error, Only one player allowed:\n");
		printf("Col: %d\nRow: %d\n", i, j);
		printf("Invalid Player: %c\n", data->space_map[i][j]);
		return (1);
	}
	return (0);
}

/**
 * @brief Check in the current (which is cannot be a '1' or a ' '), if
 *
 * @param data
 * @param i
 * @param j
 * @return int
 */
int	border_map(t_info_data *data, int i, int j)
{
	if (data->space_map[i - 1][j] == ' '
		|| data->space_map[i + 1][j] == ' '
		|| data->space_map[i][j - 1] == ' '
		|| data->space_map[i][j + 1] == ' ')
	{
		printf("ERROR, Close the map correctly:\nCol: %d\nRow: %d\n", i, j);
		return (1);
	}
	return (0);
}

int	is_mapable(int c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != 'D' && c != '0')
	{
		printf("ERROR: This character is not allowed: %c\n", c);
		return (1);
	}
	return (0);
}

int	check_map(t_info_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->space_map[i])
	{
		j = 1;
		while (data->space_map[i][j])
		{
			if (data->space_map[i][j] != '1' && data->space_map[i][j] != ' ')
			{
				if (is_mapable(data->space_map[i][j]) > 0
					|| border_map(data, i, j) > 0
						|| check_player(data, i, j) > 0)
					return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}
