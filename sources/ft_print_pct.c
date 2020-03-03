/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/28 15:10:47 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_pct(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_uint64	i;
	t_int64		pad;

	(void)va;
	i = 0;
	*ret += 1;
	pad = (fmt->width - 1);
	pad = (pad >=0) ? pad : 0;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putchar_fd('%', 1);
		while (i < (t_uint64)pad)
		{
			if (fmt->flag & FLAG_FILL_0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			*ret += 1;
			i++;
		}
		if (!(fmt->flag & FLAG_LEFT))
			ft_putchar_fd('%', 1);
	}
	else
		ft_putchar_fd('%', 1);
}
