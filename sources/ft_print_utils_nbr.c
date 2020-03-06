/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:03:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 13:05:45 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int32			ft_nbrsize(t_int64 nbr, char *b)
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
	if (!count)
		return (1);
	return (count);
}

static t_int32	ft_precsize(t_format *fmt, t_int64 nbr, char *b)
{
	t_int32		zero;

	if (!nbr && fmt->flag & FLAG_PREC && fmt->precision == 0)
		zero = 0;
	else
		zero = !nbr ? 1 : 0;
	return ((ft_nbrsize(nbr, b) < fmt->precision ? fmt->precision :
	ft_nbrsize(nbr, b)) - ft_nbrsize(nbr, b) + zero);
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

t_int32			ft_nbrlen(t_format *fmt, t_int64 nbr, char *b)
{
	t_int32		nbrsize;
	t_int32		zeros;

	if (fmt->flag & FLAG_PREC)
	{
		if (fmt->precision < 0)
			fmt->precision = 1;
		zeros = !nbr && fmt->flag & FLAG_WIDTH ? 1 : 0;
		nbrsize = ft_nbrsize(nbr, b);
		nbr *= (nbr < 0) ? -1 : 1;
		return (ft_precsize(fmt, nbr, b) + nbrsize - zeros);
	}
	else
	{
		if (nbr)
			return (ft_nbrsize(nbr, b));
		if (fmt->flag & FLAG_WIDTH && fmt->width > 0)
			return (ft_nbrsize(nbr, b));
		return (0);
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
		{
			ft_printnbr_base(nbr, b, ret);
		}
	}
	else
		ft_printnbr_base(nbr, b, ret);
}
