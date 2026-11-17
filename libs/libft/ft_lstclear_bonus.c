/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrenn <mcrenn@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:45:28 by mcrenn            #+#    #+#             */
/*   Updated: 2025/11/10 13:57:42 by mcrenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nodeforward;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nodeforward = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = nodeforward;
	}
	*lst = NULL;
}
