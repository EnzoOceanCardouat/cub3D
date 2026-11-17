/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:17:30 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/12 18:21:08 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (!dst || !src)
		return (0);
	index = 0;
	while (src[index] && ((index + 1) < size))
	{
		dst[index] = src[index];
		index++;
	}
	if (size != 0)
		dst[index] = '\0';
	return (ft_strlen(src));
}
