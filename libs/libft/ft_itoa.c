/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:55:04 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/11 14:44:45 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	strlenint(int n)
{
	size_t	len_int;

	len_int = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len_int++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}

static char	*fill_dest(int n, int i, char *dest)
{
	if (n < 0)
	{
		dest[0] = '-';
		if (n < -9)
			fill_dest(-(n / 10), i - 1, dest);
	}
	if (n > 9 && i != 0)
		fill_dest(n / 10, i - 1, dest);
	dest[i] = ft_abs(n % 10) + '0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;

	dest = ft_calloc(strlenint(n) + 1, sizeof(char));
	if (dest == 0)
		return (NULL);
	dest = fill_dest(n, strlenint(n) - 1, dest);
	return (dest);
}
