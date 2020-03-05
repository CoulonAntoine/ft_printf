/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:03:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/05 09:45:17 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int32	ft_nbrsize(t_int64 nbr, char *b)
{
	t_int32		count;

	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= ft_strlen(b);
		count++;
	}
	return (count);
}

static t_int32	ft_precsize(t_format *fmt, t_int64 nbr, char *b)
{
	return ((ft_nbrsize(nbr, b) < fmt->precision ?
	fmt->precision : ft_nbrsize(nbr, b)) - ft_nbrsize(nbr, b));
}

static void		ft_printnbr_base(t_int64 nbr, char *b, t_int32 *ret)
{
	if (nbr < (t_int64)ft_strlen(b))
		ft_putchar_pf(b[nbr], ret);
	else
	{
		ft_printnbr_base(nbr / ft_strlen(b), b, ret);
		ft_printnbr_base(nbr % ft_strlen(b), b, ret);
	}
}

void			ft_putnbr_pf(t_format *fmt, t_int64 nbr, char *b, t_int32 *ret)
{
	if (nbr < 0)
	{
		ft_putchar_pf('-', ret);
		nbr *= -1;
	}
	if (fmt->flag & FLAG_PREC)
	{
		if (fmt->precision < 0)
			fmt->precision = 1;
		ft_printpad(1, ft_precsize(fmt, nbr, b), ret);
		if (nbr)
			ft_printnbr_base(nbr, b, ret);
	}
	else
		ft_printnbr_base(nbr, b, ret);
}
