/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/10 16:15:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *s, ...)
{
	va_list		va;
	uint64_t	i;

	va_start(va, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			i += ft_parse(s + i + 1, &va);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(va);
	return (0);
}
