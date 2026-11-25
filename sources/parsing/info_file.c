/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:51:24 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/25 18:02:19 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	int	status;

	if (ft_strncmp("1", str, 1) == 0)
		data->map_set = 1;
	status = no_so_pars(data, str);
	if (status == 2)
	{
		status = we_ea_pars(data, str);
		if (status == 2)
		{
			status = door_pars(data, str);
			if (status != 2)
				return (status);
		}
		else
			return (status);
	}
	else
		return (status);
	return (-1);
}

/**
 * @brief Goes through the array and free it.
 *
 * @param array the sended array to be freed.
 */
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

/**
 * @brief Check if the ft_atoi return a valid number which is a number between
 * 0 and 255.
 *
 * @param str The sended string which is a potential color nbr.
 * @param color an address to the mlx_color of data structure.
 * @return int: 1 if an error occurs, else 0.
 */
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

/**
 * @brief Filling the data->color array (RGB).
 *
 * @param data_color The mlx_color from data structure to be filled.
 * @param str A string which correspond to the floor/cellar color.
 * @return int: return 1 if an error occurs, else 0.
 */
int	fill_color(mlx_color *data_color, char *str)
{
	int		i;
	char	**colors;

	i = 0;
	colors = ft_split_set(str + 2, ",\n");
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
	data_color->a = 255;
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
