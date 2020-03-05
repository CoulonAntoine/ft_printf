/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/05 08:54:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_ux(t_format *fmt, va_list *va, t_int32 *ret)
{
	(void)fmt;
	(void)va;
	(void)ret;
	// t_uint64	arg;
	// t_int32		pad;

	// arg = (t_uint64)va_arg(*va, unsigned int);
	// *ret += ft_hexsize(fmt, arg);
	// if (!(fmt->flag & FLAG_WIDTH))
	// 	return (ft_printhexnbr(fmt, arg, UHEX_BASE));
	// pad = (t_int32)fmt->width - (t_int32)ft_hexsize(fmt, arg);
	// pad = (pad >= 0) ? pad : 0;
	// if (fmt->flag & FLAG_LEFT)
	// 	ft_printhexnbr(fmt, (t_int64)arg, UHEX_BASE);
	// ft_printpad(fmt, pad, ret);
	// if (!(fmt->flag & FLAG_LEFT))
	// 	ft_printhexnbr(fmt, (t_int64)arg, UHEX_BASE);
}
