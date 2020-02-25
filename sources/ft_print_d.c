/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/25 14:06:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_int32	ft_nbrsize(t_int64 nbr)
{
	t_int32		count;

	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 10)
	{
		nbr /= 10;
		count++;
	}
	return (count + 1);
}

void			ft_print_d(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_int64		arg;

	(void)fmt;
	arg = (t_int64)va_arg(*va, int);
	*ret += ft_nbrsize(arg);
	ft_putchar_fd('d', 1);
}
