/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 11:47:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		va;
	uint64_t	i;

	va_start(va, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i += ft_process(format + i + 1, &va);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(va);
	return (0);
}
