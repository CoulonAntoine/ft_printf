/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/27 14:01:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_u(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_uint64	arg;
	t_int32		pad;

	arg = (t_uint64)va_arg(*va, unsigned int);
	*ret += ft_dsize(fmt, arg, 0);
	if (!(fmt->flag & FLAG_WIDTH))
		return (ft_printnbr(fmt, arg, 0));
	pad = (t_int32)fmt->width - (t_int32)ft_dsize(fmt, arg, 0);
	pad = (pad >= 0) ? pad : 0;
	if (fmt->flag & FLAG_LEFT)
		ft_printnbr(fmt, (t_int64)arg, 0);
	ft_printpad(fmt, pad, ret);
	if (!(fmt->flag & FLAG_LEFT))
		ft_printnbr(fmt, (t_int64)arg, 0);
}
