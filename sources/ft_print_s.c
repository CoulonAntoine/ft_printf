/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/04 17:15:31 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_s(t_format *fmt, va_list *va, t_int32 *ret)
{
	char		*arg;

	arg = va_arg(*va, char *);
	arg = (!arg) ? "(null)" : arg;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putstr_pf(fmt, arg, ret);
		if (!(fmt->flag & FLAG_LEFT))
			ft_putstr_pf(fmt, arg, ret);
	}
	else
		ft_putstr_pf(fmt, arg, ret);
}
