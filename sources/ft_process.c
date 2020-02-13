/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:47:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 12:16:35 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*g_specifiers[7])(t_format *, va_list *) = {0};

t_uint64		ft_process(const char *s, va_list *va)
{
	t_format	fmt;
	t_uint64	size;

	size = ft_parse(s, &fmt, va);
	ft_redirect(&fmt, va);
	g_specifiers[fmt.specifier](&fmt, va);
	return (size);
}
