/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/03 15:51:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_d(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_int64		arg;
	t_int32		sign;
	t_int32		pad;

	arg = (t_int64)va_arg(*va, int);
	if ((!(fmt->flag & FLAG_PREC) ||
	!fmt->precision) && fmt->flag & FLAG_PREC && fmt->width && arg)
	{
		fmt->precision = fmt->width;
		fmt->precision -= (arg < 0) ? 1 : 0;
		fmt->width = 0;
	}
	sign = (arg >= 0) ? 0 : 1;
	arg *= (arg >= 0) ? 1 : -1;
	*ret += ft_dsize(fmt, arg, sign);
	if (fmt->flag & FLAG_WIDTH && fmt->flag & FLAG_FILL_0 &&
	!(fmt->flag & FLAG_PREC) && sign)
	{
		sign = 0;
		fmt->width -= 1;
		ft_putchar_fd('-', 1);
	}
	if (!(fmt->flag & FLAG_WIDTH))
		return (ft_printnbr(fmt, arg, sign));
	if (fmt->flag & FLAG_WIDTH)
	{
		pad = (t_int32)fmt->width - (t_int32)ft_dsize(fmt, arg, sign);
		pad = (pad >= 0) ? pad : 0;
	}
	(fmt->flag & FLAG_LEFT) ? ft_printnbr(fmt, arg, sign) : (void)0;
	(fmt->flag & FLAG_WIDTH) ? ft_printpad(fmt, pad, ret) : (void)0;
	(!(fmt->flag & FLAG_LEFT)) ? ft_printnbr(fmt, arg, sign) : (void)0;
}
