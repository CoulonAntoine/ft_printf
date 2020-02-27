/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:06:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/27 14:26:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_base(char *base)
{
	int			i;
	int			j;

	i = 0;
	while (base[i])
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (1);
}

static void		ft_print_base(long nbr, char *base, int size)
{
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr < size)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		ft_print_base(nbr / size, base, size);
		ft_print_base(nbr % size, base, size);
	}
}

void			ft_putnbr_base(unsigned int nbr, char *base)
{
	int			size;
	long		nbr2;

	if (!base)
		return ;
	nbr2 = (long)nbr;
	size = 0;
	if (ft_is_base(base))
	{
		while (base[size])
			size++;
		ft_print_base(nbr2, base, size);
	}
}