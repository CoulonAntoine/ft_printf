/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 13:01:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_s(t_format *fmt, va_list *va)
{
	char		*arg;
	t_uint64	i;

	i = 0;
	arg = va_arg(*va, char *);
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putstr_fd(arg, 1);
		while (i < (fmt->width - ft_strlen(arg)))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if (!(fmt->flag & FLAG_LEFT))
			ft_putstr_fd(arg, 1);
	}
	else
		ft_putstr_fd(arg, 1);
}
