/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:51:24 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 18:51:09 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/**
 * @brief Register the path of every direction in the data structure
 * if the comparison with str is valid.
 *
 * @param data The structure of all the parsing system.
 * @param str The current string extracted from the ".cub" file.
 * @return int: 1 if none of the paths are founded, else 0.
 */
int	pars_texture(t_info_data *data, char *str)
{
	if (ft_strncmp("NO ", str, 3) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			return (5);
		free(data->north_texture);
		data->north_texture = ft_substr(str, 3, ft_strlen(str) - 4);
		if (!data->north_texture)
			return (1);
		++data->header_nb_rows;
		return (0);
	}
	else if (ft_strncmp("SO ", str, 3) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			return (5);
		free(data->south_texture);
		data->south_texture = ft_substr(str, 3, ft_strlen(str) - 4);
		if (!data->south_texture)
			return (1);
		++data->header_nb_rows;
		return (0);
	}
	else if (ft_strncmp("WE ", str, 3) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			return (5);
		free(data->west_texture);
		data->west_texture = ft_substr(str, 3, ft_strlen(str) - 4);
		if (!data->west_texture)
			return (1);
		++data->header_nb_rows;
		return (0);
	}
	else if (ft_strncmp("EA ", str, 3) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			return (5);
		free(data->east_texture);
		data->east_texture = ft_substr(str, 3, ft_strlen(str) - 4);
		if (!data->east_texture)
			return (1);
		++data->header_nb_rows;
		return (0);
	}
	else if (ft_strncmp("DO ", str, 3) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			return (5);
		free(data->door_texture);
		data->door_texture = ft_substr(str, 3, ft_strlen(str) - 4);
		if (!data->door_texture)
			return (1);
		++data->header_nb_rows;
		return (0);
	}
	return (-1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	atoi_checker(char *str, uint8_t *color)
{
	int	is_rgb;
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	is_rgb = ft_atoi(str);
	if (is_rgb < 0 || is_rgb > 255)
		return (1);
	*color = is_rgb;
	return (0);
}

int	fill_color(mlx_color *data_color, char *str)
{
	int		i;
	char	**colors;

	i = 0;
	colors = ft_split(str + 2, ",\n");
	if (!colors)
		return (1);
	while (colors[i])
		i++;
	if (i != 3)
	{
		free_array(colors);
		return (1);
	}
	if (atoi_checker(colors[0], &data_color->r) > 0
		|| atoi_checker(colors[1], &data_color->g) > 0
			|| atoi_checker(colors[2], &data_color->b) > 0)
	{
		free_array(colors);
		return (4);
	}
	free_array(colors);
	return (0);
}

/**
 * @brief Register the color of the floor/ceiling in the data structure
 * if the comparison with str is valid.
 *
 * @param data The structure of all the parsing system.
 * @param str The current string extracted from the ".cub" file.
 * @return int: 1 if no one of the floor/ceilling are founded, else 0.
 */
int	pars_flr_clr(t_info_data *data, char *str)
{
	int	error_ret;

	if (ft_strncmp("F ", str, 2) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			ft_exit(5, data);
		error_ret = fill_color(&data->floor_color, str);
		if (error_ret > 0)
			return (error_ret);
		data->floor_set = true;
		++data->header_nb_rows;
		return (0);
	}
	else if (ft_strncmp("C ", str, 2) == 0)
	{
		if (data->file_nb_total_rows != data->header_nb_rows)
			ft_exit(5, data);
		error_ret = fill_color(&data->ceiling_color, str);
		if (error_ret > 0)
			return (error_ret);
		data->celling_set = true;
		++data->header_nb_rows;
		return (0);
	}
	return (-1);
}
