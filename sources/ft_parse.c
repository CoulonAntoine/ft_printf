/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:38:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/28 11:18:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64		ft_parse(const char *s, t_format *fmt, va_list *va)
{
	t_uint64	i;

	i = 0;
	fmt->flag = 0;
	if (!s[i])
		return (0);
	i += ft_parse_flags(fmt, (char *)s + i);
	if (!s[i])
		return (0);
	i += ft_parse_width(fmt, (char *)s + i, va);
	if (!s[i])
		return (0);
	i += ft_parse_precision(fmt, (char *)s + i, va);
	if (!s[i])
		return (0);
	i += ft_parse_specifier(fmt, (char *)s + i);
	return (i);
}
