/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 12:14:19 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpref(t_int32 *ret)
{
	ft_putchar_pf('0', ret);
	ft_putchar_pf('x', ret);
}

void		ft_print_p(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_uint64		arg;

	arg = (unsigned long)va_arg(*va, void *);
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
		{
			ft_putpref(ret);
			ft_putp_pf(fmt, arg, HEX_BASE, ret);
		}
		ft_printpad((fmt->flag & FLAG_PREC) ? 0 : fmt->flag & FLAG_FILL_0,
		fmt->width - ft_plen(fmt, arg, HEX_BASE) - 2, ret);
		if (!(fmt->flag & FLAG_LEFT))
		{
			ft_putpref(ret);
			ft_putp_pf(fmt, arg, HEX_BASE, ret);
		}
	}
	else
	{
		ft_putpref(ret);
		ft_putp_pf(fmt, arg, HEX_BASE, ret);
	}
}
