/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:03:47 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/28 11:10:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int32			ft_hexnbrsize(t_int64 nbr)
{
	t_int32		count;

	if (nbr == 0)
		return (1);
	count = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

t_int32			ft_hexsize(t_format *fmt, t_int64 nbr)
{
	if (!(fmt->flag & FLAG_PREC))
		return (ft_hexnbrsize(nbr));
	if (fmt->precision > (t_uint64)ft_hexnbrsize(nbr))
		return (fmt->precision);
	return (ft_hexnbrsize(nbr));
}

void			ft_printhexnbr(t_format *fmt, t_int64 nbr, char *base)
{
	t_int32		zeros;
	t_int32		i;

	i = 0;
	if (!(fmt->flag & FLAG_PREC))
	{
		ft_putnbr_base(nbr, base);
		return ;
	}
	zeros = (t_int32)fmt->precision - (t_int32)ft_hexnbrsize(nbr);
	zeros = (zeros < 0) ? 0 : zeros;
	while (i < zeros)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	if (!nbr && fmt->precision == 0 && fmt->width)
	{
	 	ft_putchar_fd(' ', 1);
		return ;
	}
	if (!nbr && fmt->precision == 0 && !fmt->width)
		return ;
	else
		ft_putnbr_base(nbr, base);
}
