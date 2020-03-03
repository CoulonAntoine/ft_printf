/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/28 15:15:01 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_c(t_format *fmt, va_list *va, t_int32 *ret)
{
	char		arg;
	t_uint64	i;
	t_int64		pad;

	i = 0;
	arg = (char)va_arg(*va, int);
	*ret += 1;
	pad = (fmt->width - 1);
	pad = (pad >= 0) ? pad : 0;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putchar_fd(arg, 1);
		while (i < (t_uint64)pad)
		{
			ft_putchar_fd(' ', 1);
			*ret += 1;
			i++;
		}
		if (!(fmt->flag & FLAG_LEFT))
			ft_putchar_fd(arg, 1);
	}
	else
		ft_putchar_fd(arg, 1);
}
