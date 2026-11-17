/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:43:52 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 18:26:54 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

/* Main which is the start of the Cube3D project! */

int main(int ac, char **av)
{
	// NE PAS OUBLIER L'EXTENSION "bonus" sur les fichiers !
	t_info_data	*data;

	if (ac != 2)
		return (1);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		//Error
		return (1);
	}
	data = ft_calloc(1, sizeof(t_info_data));
	if (!data)
		return (1);
	parsing(av[1], data);
	ft_exit(0, data);
}
