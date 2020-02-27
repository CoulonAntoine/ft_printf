/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:03:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/27 13:55:20 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_int32	ft_nbrsize(t_int64 nbr)
{
	t_int32		count;

	count = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 10)
	{
		nbr /= 10;
		count++;
	}
	return (count + 1);
}

t_int32			ft_dsize(t_format *fmt, t_int64 nbr, t_int16 sign)
{
	if (!(fmt->flag & FLAG_PREC))
		return (ft_nbrsize(nbr) + sign);
	if (fmt->precision > (t_uint64)ft_nbrsize(nbr))
		return (fmt->precision + sign);
	return (ft_nbrsize(nbr) + sign);
}

void			ft_printnbr(t_format *fmt, t_int64 nbr, t_int32 sign)
{
	t_int32		zeros;
	t_int32		i;

	if (sign)
		ft_putchar_fd('-', 1);
	i = 0;
	if (!(fmt->flag & FLAG_PREC))
	{
		ft_putnbr_fd(nbr, 1);
		return ;
	}
	zeros = (t_int32)fmt->precision - (t_int32)ft_nbrsize(nbr);
	zeros = (zeros < 0) ? 0 : zeros;
	while (i < zeros)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	if (!nbr && fmt->precision == 0 && fmt->width)
		ft_putchar_fd(' ', 1);
	else if (!nbr && fmt->precision == 0 && !fmt->width)
		return ;
	else
		ft_putnbr_fd(nbr, 1);
}

void			ft_printpad(t_format *fmt, t_int32 pad, t_int32 *ret)
{
	t_int32		i;

	i = 0;
	while (i < pad)
	{
		if (fmt->flag & FLAG_FILL_0 && !(fmt->flag & FLAG_PREC))
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		*ret += 1;
		i++;
	}
}
