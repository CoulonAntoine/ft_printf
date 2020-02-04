/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 07:46:05 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 12:10:03 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	int		diff;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < (int)n)
	{
		diff = (int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (diff)
			return (diff);
		i++;
	}
	return (0);
}
