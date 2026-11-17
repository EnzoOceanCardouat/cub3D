/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:42:54 by mcrenn            #+#    #+#             */
/*   Updated: 2026/04/03 15:36:43 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Funcion that convert ASCII characters to INT digits.
 *
 * @param nptr The string receves has argument.
 * @return int
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	if (!nptr)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (ft_isdigit(nptr[i]) == 0)
			return (result * sign);
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
