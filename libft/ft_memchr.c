/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 07:33:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 12:09:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*s_cpy;

	if (!s)
		return (NULL);
	i = 0;
	s_cpy = (void *)s;
	while (i < n)
	{
		if (((unsigned char *)s_cpy)[i] == (unsigned char)c)
			return (s_cpy + i);
		i++;
	}
	return (NULL);
}
