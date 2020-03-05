/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/05 08:28:02 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_pct(t_format *fmt, va_list *va, t_int32 *ret)
{

	(void)va;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putchar_pf('%', ret);
		ft_printpad(fmt->flag & FLAG_FILL_0, fmt->width - 1, ret);
		if (!(fmt->flag & FLAG_LEFT))
			ft_putchar_pf('%', ret);
	}
	else
		ft_putchar_pf('%', ret);
}
