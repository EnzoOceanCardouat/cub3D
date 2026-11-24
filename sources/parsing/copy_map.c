/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:36:36 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/24 13:34:02 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
