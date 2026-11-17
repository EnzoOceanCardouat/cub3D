/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:29:09 by mcrenn            #+#    #+#             */
/*   Updated: 2026/11/17 17:56:32 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index ++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[index]);
	}
	return (NULL);
}
