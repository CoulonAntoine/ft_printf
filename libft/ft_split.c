/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:02:05 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 12:13:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_clean(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int		ft_wc(char const *str, char c)
{
	int		i;
	int		wc;

	wc = 0;
	if (str[0] != c)
		wc++;
	i = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			wc++;
		i++;
	}
	return (wc);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	str_i;
	char	**strs;

	if (!s || !(strs = malloc(sizeof(char *) * (ft_wc(s, c) + 1))))
		return (NULL);
	i = 0;
	str_i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
		{
			if (!(strs[str_i] = ft_strndup((char *)&s[i], j)))
				return (ft_clean(strs));
			str_i++;
			i += j;
		}
		i += (s[i]) ? 1 : 0;
	}
	strs[str_i] = NULL;
	return (strs);
}
