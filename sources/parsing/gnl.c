/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:26:56 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 08:41:49 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft/libft.h"

static char	*join_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static char	*storer(char *buffer, int fd)
{
	char	*stock;
	int		reader;

	reader = 1;
	stock = malloc((size_t)BUFFER_SIZE + 1);
	if (!stock)
	{
		free(buffer);
		return (NULL);
	}
	while (!ft_strchr(buffer, '\n') && reader > 0)
	{
		reader = read(fd, stock, BUFFER_SIZE);
		if (reader < 0)
		{
			free(stock);
			free(buffer);
			return (NULL);
		}
		if (reader == 0)
			break ;
		stock[reader] = '\0';
		//buffer = ft_strjoin(buffer, stock);
		buffer = join_free(buffer, stock);
		if (!buffer)
		{
			free(stock);
			return (NULL);
		}
	}
	free(stock);
	return (buffer);
}

static char	*line_extractor(char *buffer)
{
	char	*current_line;
	int		i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	current_line = ft_calloc(sizeof(char), i + 1);
	if (!current_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		current_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		current_line[i++] = '\n';
	current_line[i] = '\0';
	return (current_line);
}

static char	*buffer_updater(char *buffer)
{
	char	*updated_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	updated_buffer = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
	if (!updated_buffer)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	i++;
	while (buffer[i])
		updated_buffer[j++] = buffer[i++];
	free(buffer);
	return (updated_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*current_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (NULL);
	buffer = storer(buffer, fd);
	if (!buffer)
		return (NULL);
	current_line = line_extractor(buffer);
	if (!current_line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = buffer_updater(buffer);
	return (current_line);
}
