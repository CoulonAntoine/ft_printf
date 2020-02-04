/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:13:22 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 12:27:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	long	start;
	long	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strinc(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strinc(s1[end], set))
		end--;
	len = (end >= start) ? end - start : 0;
	return (ft_substr(s1, start, len + 1));
}
