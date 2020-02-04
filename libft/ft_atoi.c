/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:40:26 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/10 11:16:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	long long		nbr;
	int				sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-' && str[i++])
		sign *= -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (nbr < 0)
			return (sign > 0 ? -1 : 0);
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}
