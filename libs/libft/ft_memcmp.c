/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:39:44 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/12 18:24:43 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while ((src1[i] == src2[i]) && (i < (n - 1)))
		i++;
	return (src1[i] - src2[i]);
}
