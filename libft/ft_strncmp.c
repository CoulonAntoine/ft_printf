/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:39:39 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 12:29:16 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	if (n < 1)
		return (0);
	while (s1_copy[i] == s2_copy[i] && i < (n - 1))
	{
		if (s1_copy[i] == '\0')
			return (0);
		i++;
	}
	return (s1_copy[i] - s2_copy[i]);
}
