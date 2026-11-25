/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:36:36 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/25 17:24:00 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Copy the current string in file corresponding to a line in map.
 *
 * @param data The structure of all the parsing system.
 * @param str The address of the curent string in file.
 * @param fd The file descriptor.
 * @param i The current index.
 */
static void	copy_save_map(t_info_data *data, char **str, int fd, int *i)
{
	data->map[*i] = ft_calloc(ft_strlen(*str) + 1, sizeof(char));
	if (!data->map[*i])
	{
		close(fd);
		ft_exit(1, data);
	}
	ft_strlcpy(data->map[*i], *str, ft_strlen(*str));
	if (ft_strlen(*str) > data->map_width)
		data->map_width = ft_strlen(*str);
	++data->map_length;
	++*i;
	free(*str);
	*str = get_next_line(fd);
}

/**
 * @brief Goes through the file while until the map is reached.
 *
 * @param file The name of the file .cub .
 * @param data The structure of all the parsing system.
 * @return int: return 0.
 */
int	save_map(char *file, t_info_data *data)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	data->map = ft_calloc(data->file_nb_total_rows - data->header_nb_rows + 1,
			sizeof(char *));
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
		copy_save_map(data, &str, fd, &i);
	close(fd);
	return (0);
}

/**
 * @brief Copy the content of 'data->map' to 'data->space_map', the first and
 * the last part of the array are composed by space ' '.
 *
 * @param len the size of the 'data->map' previous string.
 * @param i the current index of the map.
 * @param j the current index of the map[i].
 * @param data The structure of all the parsing system.
 */
static void	else_copy_map(size_t *len, size_t i, size_t *j, t_info_data *data)
{
	*len = ft_strlen(data->map[i - 1]);
	*j = 0;
	while (*j < data->map_width + 1)
	{
		if (*j == 0 || *j > *len || data->map[i - 1][*j - 1] == ' ')
			data->space_map[i][*j] = ' ';
		else
			data->space_map[i][*j] = data->map[i - 1][*j - 1];
		++*j;
	}
}

/**
 * @brief Create a copy of data->map, but bordered by space ' ', filling
 * data->space_map.
 *
 * @param data The structure of all the parsing system.
 * @return int: 1 if an allocation failed, else 0.
 */
int	copy_map(t_info_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**sp_map;

	sp_map = ft_calloc(data->file_nb_total_rows - data->header_nb_rows + 3,
			sizeof(char *));
	data->space_map = sp_map;
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
			else_copy_map(&len, i, &j, data);
		++i;
	}
	return (0);
}
