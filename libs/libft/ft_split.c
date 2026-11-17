/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:11:02 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 18:06:05 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_substring_nb(const char *str, const char *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (str[i] && ft_strchr(set, str[i]) == NULL)
		count++;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
		{
			while (str[i] && ft_strchr(set, str[i]))
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count);
}

static	size_t	get_substr_size(const char *str, const char *set, size_t cur)
{
	size_t	count;
	size_t	size;
	size_t	i;

	count = 0;
	size = 0;
	i = 0;
	if (str[i] && ft_strchr(set, str[i]) == NULL)
		count++;
	while (str[i] && size == 0)
	{
		if (count == cur + 1)
			while (str[i] && ft_strchr(set, str[i++]) == NULL)
				size++;
		else if (ft_strchr(set, str[i]))
		{
			while (str[i] && ft_strchr(set, str[i]))
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (size);
}

static void	set_substr(char *sub, const char *str, const char *set, size_t cur)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	j = 0;
	if (str[i] && ft_strchr(set, str[i]) == NULL)
		count++;
	while (str[i] && j == 0)
	{
		if (count == cur + 1)
			while (str[i] && ft_strchr(set, str[i]) == NULL)
				sub[j++] = str[i++];
		else if (ft_strchr(set, str[i]))
		{
			while (str[i] && ft_strchr(set, str[i]))
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
}

static void	free_to_index(char **split, size_t goal)
{
	size_t	i;

	i = 0;
	while (i < goal)
		free(split[i++]);
	free(split);
}

char	**ft_split(const char *str, const char *set)
{
	char	**split;
	size_t	nb_substrings;
	size_t	i;

	if (!str || !*str || !set)
		return (NULL);
	nb_substrings = get_substring_nb(str, set);
	split = ft_calloc(nb_substrings + 1, sizeof(char **));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < nb_substrings)
	{
		split[i] = ft_calloc(get_substr_size(str, set, i), sizeof(char *));
		if (!split[i])
		{
			free_to_index(split, i);
			return (NULL);
		}
		set_substr(split[i], str, set, i);
		i++;
	}
	return (split);
}
