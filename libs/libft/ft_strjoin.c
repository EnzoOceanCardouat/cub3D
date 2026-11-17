/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:22:32 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/09 00:36:12 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc((len + 1), sizeof(char));
	if (dest == 0)
		return (NULL);
	ft_strlcat(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, (len + 1));
	return (dest);
}
