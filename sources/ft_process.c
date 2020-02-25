/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:47:34 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/25 12:19:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*g_specifiers[8])(t_format *, va_list *, t_int32 *) = {
	&ft_print_c,
	&ft_print_s,
	&ft_print_p,
	&ft_print_d,
	&ft_print_u,
	&ft_print_x,
	&ft_print_ux,
	&ft_print_pct
};

t_uint64		ft_process(const char *s, va_list *va, t_int32 *ret)
{
	t_format	fmt;
	t_uint64	size;

	size = ft_parse(s, &fmt, va);
	g_specifiers[fmt.specifier](&fmt, va, ret);
	return (size);
}
