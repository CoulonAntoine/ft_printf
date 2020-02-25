/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/25 12:25:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnstr(char *arg, t_format *fmt)
{
	t_uint64	i;
	t_uint64	prec;

	if (fmt->flag & FLAG_PREC)
	{
		i = 0;
		prec = fmt->precision;
		while (i < prec)
		{
			ft_putchar_fd(arg[i], 1);
			i++;
		}
		return ;
	}
	ft_putstr_fd(arg, 1);
}

static t_uint64	ft_size(char *arg, t_format *fmt)
{
	if (!(fmt->flag & FLAG_PREC))
		return (ft_strlen(arg));
	return (ft_strlen(arg) < fmt->precision ? ft_strlen(arg) : fmt->precision);
}

void			ft_print_s(t_format *fmt, va_list *va, t_int32 *ret)
{
	char		*arg;
	t_uint64	i;

	arg = va_arg(*va, char *);
	if (!arg)
		arg = "(null)";
	if (fmt->flag & FLAG_WIDTH)
	{
		i = 0;
		if (fmt->flag & FLAG_LEFT)
			ft_putnstr(arg, fmt);
		while (fmt->width >= ft_size(arg, fmt) &&
		i < (fmt->width - ft_size(arg, fmt)))
		{
			ft_putchar_fd(' ', 1);
			*ret += 1;
			i++;
		}
		if (!(fmt->flag & FLAG_LEFT))
			ft_putnstr(arg, fmt);
	}
	else
		ft_putnstr(arg, fmt);
	*ret += ft_size(arg, fmt);
}
