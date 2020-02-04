/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:13:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 12:35:46 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char const *str, int len)
{
	int		i;
	char	*cpy;

	if (!str)
		return (NULL);
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
