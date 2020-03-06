/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 12:18:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int32			ft_strsize(t_format *fmt, char *s)
{
	if (!(fmt->flag & FLAG_PREC) || fmt->precision < 0)
		return (ft_strlen(s));
	return ((t_uint64)fmt->precision > ft_strlen(s) ?
	ft_strlen(s) : fmt->precision);
}

void			ft_print_s(t_format *fmt, va_list *va, t_int32 *ret)
{
	char		*arg;

	arg = va_arg(*va, char *);
	arg = (!arg) ? "(null)" : arg;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putstr_pf(fmt, arg, ret);
		ft_printpad(fmt->flag & FLAG_FILL_0,
		fmt->width - ft_strsize(fmt, arg), ret);
		if (!(fmt->flag & FLAG_LEFT))
			ft_putstr_pf(fmt, arg, ret);
	}
	else
		ft_putstr_pf(fmt, arg, ret);
}
