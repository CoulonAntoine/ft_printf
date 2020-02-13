/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:47:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 12:35:35 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*g_specifiers[8])(t_format *, va_list *) = {
	&ft_print_c,
	&ft_print_s,
	&ft_print_p,
	&ft_print_d,
	&ft_print_u,
	&ft_print_x,
	&ft_print_ux,
	&ft_print_prc
};

t_uint64		ft_process(const char *s, va_list *va)
{
	t_format	fmt;
	t_uint64	size;

	size = ft_parse(s, &fmt, va);
	g_specifiers[fmt.specifier](&fmt, va);
	return (size);
}