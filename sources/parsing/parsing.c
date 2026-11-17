/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:05:46 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 18:48:39 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/**
 * @brief Check in the struct data if all paths and the color of floor/ceiling
 * are correctly registred.
 *
 * @param data The structure of all the parsing system.
 * @return int: 1 if a path/color is missed, 0 if everything is fine.
 */
int	check_ressources(t_info_data *data)
{
	if (!data->north_texture || !data->south_texture
		|| !data->east_texture || !data->west_texture)
	{
		printf("Error: One texure path is missing or misspelled.\n");
		return (1);
	}
	if (data->celling_set < 1 || data->floor_set < 1)
	{
		printf("Error: Color indication of the celling/floor is missing.\n");
		return (1);
	}
	return (0);
}

static void	free_gnl(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}

int	filling_structure(t_info_data *data, int fd)
{
	char*	str;
	int		color_ret_code;
	int		texture_ret_code;

	str = get_next_line(fd);
	while (str)
	{
		color_ret_code = pars_flr_clr(data, str);
		if (color_ret_code > 0)
		{
			free(str);
			free_gnl(fd);
			return (color_ret_code);
		}
		texture_ret_code = pars_texture(data, str);
		if (texture_ret_code > 0)
		{
			free(str);
			free_gnl(fd);
			return (texture_ret_code);
		}
		if (ft_strncmp("\n", str, ft_strlen(str)) == 0)
			++data->header_nb_rows;
		++data->file_nb_total_rows;
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}

void	parsing(char *file, t_info_data *data)
{
	int			file_fd;
	int			error_code;

	file_fd = open(file, O_RDONLY);
	if (file_fd < 0)
	{
		//Error
		ft_exit(1, data);
	}
	error_code = filling_structure(data, file_fd);
	if (error_code > 0)
	{
		close(file_fd);
		ft_exit(error_code, data);
	}
	close(file_fd);
	save_map(file, data);
	if (check_ressources(data) == 1)
		ft_exit(10, data);
	copy_map(data);
	if (check_map(data))
		ft_exit(10, data);
}
