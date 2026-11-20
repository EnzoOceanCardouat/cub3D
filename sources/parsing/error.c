/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:45:41 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/18 16:39:02 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_message(int error_mng)
{
	if (error_mng == 1)
		printf("Allocation failed\n");
	if (error_mng == 2)
		printf("Color indication of the celling/floor is missing.\n");
	if (error_mng == 3)
		printf("Floor/Ceiling is not setup correctly.\n");
	if (error_mng == 4)
		printf("RGB color can only work between 0 and 255.\n");
	if (error_mng == 5)
		printf("Header can onnly be at start of config file\n");
}

void	free_map(t_info_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->north_texture)
		free(data->north_texture);
	if (data->south_texture)
		free(data->south_texture);
	if (data->west_texture)
		free(data->west_texture);
	if (data->east_texture)
		free(data->east_texture);
	if (data->door_texture)
		free(data->door_texture);
	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	if (data->map)
		free(data->map);
	i = 0;
	while (data->space_map && data->space_map[i])
		free(data->space_map[i++]);
	if (data->space_map)
		free(data->space_map);
	free(data);
}

void	ft_exit(int error_code, t_info_data *data)
{
	if (error_code != 0)
		error_message(error_code);
	free_map(data);
	exit(error_code);
}

char	*join_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

void	free_reader_negative(char *buffer, char **stock)
{
	free(buffer);
	free(*stock);
}
