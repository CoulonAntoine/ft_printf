/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:59:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/08 19:33:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_isset(char c, char *set)
{
	t_uint64	i;

	if (!set)
		return (FALSE);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
