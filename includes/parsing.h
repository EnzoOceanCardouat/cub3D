/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecardoua <ecardoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:38:24 by ecardoua          #+#    #+#             */
/*   Updated: 2026/11/23 13:39:04 by ecardoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_info_data
{
	char		player;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*door_texture;
	char		**map;
	char		**space_map;
	size_t		map_length;
	size_t		map_width;
	bool		celling_set;
	bool		floor_set;
	int			header_nb_rows;
	int			file_nb_total_rows;
	mlx_color	floor_color;
	mlx_color	ceiling_color;
}	t_info_data;

char	*get_next_line(int fd);
void	parsing(char *file, t_info_data *data);
int		pars_texture(t_info_data *data, char *str);
int		pars_flr_clr(t_info_data *data, char *str);
void	error_message(int error_mng);
int		save_map(char *file, t_info_data *data);
int		copy_map(t_info_data *data);
int		check_map(t_info_data *data);
int		no_so_pars(t_info_data *data, char *str);
int		we_ea_pars(t_info_data *data, char *str);
int		door_pars(t_info_data *data, char *str);

void	ft_exit(int error_code, t_info_data *data);
void	free_map(t_info_data *data);
void	free_reader_negative(char *buffer, char **stock);
char	*join_free(char *s1, char *s2);

char	**ft_split_set(const char *str, const char *set);

int		copy_map(t_info_data *data);
int		save_map(char *file, t_info_data *data);

#endif
