/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:25:23 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/29 20:05:56 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;

	if (!lst || !*lst || !del)
		return ;
	first = *lst;
	while (*lst)
	{
		*lst = first->next;
		ft_lstdelone(first, del);
		first = *lst;
	}
	*lst = 0;
}
