/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:11:18 by mcrenn            #+#    #+#             */
/*   Updated: 2026/04/10 16:27:26 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that set to 0 ('\0') all n characters of the pointer.
 *
 * @param s The gived pointer.
 * @param n The number of bites.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
