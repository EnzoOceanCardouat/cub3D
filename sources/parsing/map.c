/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:55:58 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 18:53:42 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

#include <stdio.h>

int	copy_map(t_info_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;

	data->space_map = ft_calloc(data->file_nb_total_rows - data->header_nb_rows + 3, sizeof(char *));
	if (!data->space_map)
		return (1);
	i = 0;
	while (i <= data->map_length + 1)
	{
		data->space_map[i] = ft_calloc(data->map_width + 3, sizeof(char));
		if (!data->space_map[i])
			return (1);
		if (i == 0 || i == data->map_length + 1)
			ft_memset(data->space_map[i], ' ', data->map_width + 1);
		else
		{
			len = ft_strlen(data->map[i - 1]);
			j = 0;
			while (j < data->map_width + 1)
			{
				if (j == 0 || j > len || data->map[i - 1][j - 1] == ' ')
					data->space_map[i][j] = ' ';
				else
					data->space_map[i][j] = data->map[i - 1][j - 1];
				++j;
			}
		}
		++i;
	}
	return (0);
}

	// i = 0;
	// while (data->space_map[i])
	// {
	// 	printf("MAP:|%s|\n", data->space_map[i]);
	// 	i++;
	// }

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
// #TODO Finish the commenting of this function !

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

int	save_map(char *file, t_info_data *data)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	data->map = ft_calloc(data->file_nb_total_rows - data->header_nb_rows + 1, sizeof(char *));
	if (!data->map)
	{
		close(fd);
		ft_exit(1, data);
	}
	str = get_next_line(fd);
	while (str && i++ < data->header_nb_rows)
	{
		free(str);
		str = get_next_line(fd);
	}
	i = 0;
	while (i < data->file_nb_total_rows - data->header_nb_rows)
	{
		data->map[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
		if (!data->map[i])
		{
			close(fd);
			ft_exit(1, data);
		}
		ft_strlcpy(data->map[i], str, ft_strlen(str));
		if (ft_strlen(str) > data->map_width)
			data->map_width = ft_strlen(str);
		++data->map_length;
		++i;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
