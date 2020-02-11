/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:38:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/10 19:25:00 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64		ft_parse(const char *s, va_list *va)
{
	t_uint64	i;
	t_format	fmt;

	(void)va;
	i = 1;
	i += ft_get_flags(&fmt, (char *)s + i);
	i += ft_get_width(&fmt, (char *)s + i);
	i += ft_get_precision(&fmt, (char *)s + i);
	i += ft_get_specifier(&fmt, (char *)s + i);
	//ft_process(&fmt);
	return (i);
}
