/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/03 13:32:35 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		va;
	t_uint64	i;
	t_int32		ret;

	va_start(va, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i += ft_process(format + i + 1, &va, &ret);
		else
		{
			ft_putchar_fd(format[i], 1);
			ret++;
		}
		i++;
	}
	va_end(va);
	return (i);
}
