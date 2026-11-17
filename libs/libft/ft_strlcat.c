/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:05:37 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/12 18:21:44 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	if (!dest || !src)
		return (0);
	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	ret = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] && i < (size - 1))
		i++;
	if ((dest[i] != '\0') || (size == 0))
		return (ft_strlen(src) + size);
	while (src[j] && (i < (size -1)))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ret);
}
