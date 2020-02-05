/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:09 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/04 13:44:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_smap(const char *s, va_list va)
{
	size_t	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '%')
		{

		}
		else
		{
			ft_putchar_fd(s[i], 1);
		}
		i++;
	}
}

int			ft_printf(const char *s, ...)
{
	va_list	va;

	va_start(va, s);
	va_end(va);
	return (0);
}
