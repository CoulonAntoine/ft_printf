/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/28 11:24:55 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_p(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_uint64	arg;
	t_int64		pad;

	arg = (t_uint64)va_arg(*va, void *);
	if (fmt->flag & FLAG_WIDTH)
	{
		pad = fmt->width - ft_hexnbrsize(arg) - 2;
		pad = (pad >= 0) ? pad : 0;
		pad += (fmt->flag & FLAG_PREC && !arg) ? 1 : 0;
		*ret -= (fmt->flag & FLAG_PREC && !arg) ? 1 : 0;
	}
	*ret += ft_hexnbrsize(arg) + 2;
	if (fmt->flag & FLAG_LEFT)
	{
		ft_putstr_fd("0x", 1);
		if (!(fmt->flag & FLAG_PREC && arg == 0))
			ft_putnbr_base((unsigned long)arg, HEX_BASE);
	}
	if (fmt->flag & FLAG_WIDTH)
		ft_printpad(fmt, pad, ret);
	if (!(fmt->flag & FLAG_LEFT))
	{
		ft_putstr_fd("0x", 1);
		if (!(fmt->flag & FLAG_PREC && arg == 0))
			ft_putnbr_base((unsigned long)arg, HEX_BASE);
	}
}
