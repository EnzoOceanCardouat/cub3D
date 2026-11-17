/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 00:09:07 by mcrenn            #+#    #+#             */
/*   Updated: 2026/04/18 14:30:13 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that allocates memory and put all bytes to 0
 *
 * @param nmemb The number of element to allocate.
 * @param size The size of byte of an alement (sizeof).
 * @return void*
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
	{
		tab = malloc(0);
		if (tab == NULL)
			return (NULL);
		return (tab);
	}
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
