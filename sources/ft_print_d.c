/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/26 16:04:10 by ancoulon         ###   ########.fr       */
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

static t_int32	ft_size(t_format *fmt, t_int64 nbr, t_int16 sign)
{
	if (!(fmt->flag & FLAG_PREC))
		return (ft_nbrsize(nbr) + sign);
	if (fmt->precision > (t_uint64)ft_nbrsize(nbr))
		return (fmt->precision + sign);
	return (ft_nbrsize(nbr) + sign);
}

static void		ft_printnbr(t_format *fmt, t_int64 nbr, t_int16 sign)
{
	t_int32		oversize;
	
	if (sign)
		ft_putchar_fd(1, '-');
	if (fmt->precision > (t_uint64)ft_nbrsize(nbr))
	{
		
	}
}

void			ft_print_d(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_int64		arg;
	t_int16		sign;

	arg = (t_int64)va_arg(*va, int);
	sign = (arg >= 0) ? 0 : 1;
	arg *= (arg >= 0) ? 1 : -1;
	*ret += ft_size(fmt, arg, sign);
	ft_putchar_fd('d', 1);
}
