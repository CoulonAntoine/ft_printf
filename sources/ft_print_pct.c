/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/25 12:22:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_pct(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_uint64	i;

	(void)va;
	i = 0;
	*ret += 1;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putchar_fd('%', 1);
		while (i < (fmt->width - 1))
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
