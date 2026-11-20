/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:33:24 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/18 16:33:58 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	no_so_pars(t_info_data *data, char *str)
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
	return (2);
}

int	we_ea_pars(t_info_data *data, char *str)
{
	if (ft_strncmp("WE ", str, 3) == 0)
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
	return (2);
}

int	door_pars(t_info_data *data, char *str)
{
	if (ft_strncmp("DO ", str, 3) == 0)
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
	return (2);
}
