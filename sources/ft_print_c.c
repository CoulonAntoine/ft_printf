/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 11:29:37 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_c(t_format *fmt, va_list *va, t_int32 *ret)
{
	char		arg;

	arg = (char)va_arg(*va, int);
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putchar_pf(arg, ret);
		ft_printpad(fmt->flag & FLAG_FILL_0, fmt->width - 1, ret);
		if (!(fmt->flag & FLAG_LEFT))
			ft_putchar_pf(arg, ret);
	}
	else
	{
		ft_putchar_pf(arg, ret);
	}
}
