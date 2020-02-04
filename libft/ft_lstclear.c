/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:42:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/17 09:23:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*el;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	el = *lst;
	while (el)
	{
		tmp = el->next;
		ft_lstdelone(el, del);
		el = tmp;
	}
	*lst = NULL;
}
