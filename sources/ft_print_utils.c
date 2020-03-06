/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:39:13 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 12:20:35 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar_pf(char c, t_int32 *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

void			ft_printpad(t_int32 zero, t_int32 size, t_int32 *ret)
{
	t_int32		i;

	i = 0;
	while (i < size)
	{
		ft_putchar_pf((zero) ? '0' : ' ', ret);
		i++;
	}
}

void			ft_putstr_pf(t_format *fmt, char *str, t_int32 *ret)
{
	t_int32	i;

	if (!fmt)
		return ;
	if (fmt->flag & FLAG_PREC && fmt->precision >= 0)
	{
		i = 0;
		while (str[i] && i < fmt->precision)
		{
			ft_putchar_pf(str[i], ret);
			i++;
		}
	}
	else
	{
		*ret += ft_strlen(str);
		write(1, str, ft_strlen(str));
	}
}
