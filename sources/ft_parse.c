/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:38:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 12:02:21 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64		ft_parse(const char *s, t_format *fmt, va_list *va)
{
	t_uint64	i;

	i = 0;
	fmt->flag = 0;
	i += ft_parse_flags(fmt, (char *)s + i);
	i += ft_parse_width(fmt, (char *)s + i, va);
	i += ft_parse_precision(fmt, (char *)s + i, va);
	i += ft_parse_specifier(fmt, (char *)s + i);
	return (i);
}

/*
**static const char	*byte_to_binary(int x)
**{
**   static char	b[9];
**	b[0] = '\0';
**    int z;
**    for (z = 128; z > 0; z >>= 1)
**    {
**        strcat(b, ((x & z) == z) ? "1" : "0");
**    }
**
**    return b;
**}
**
**static void		ft_print_format(t_format fmt)
**{
**	printf("t_format\nflag: |%s|\nwidth: |%ld|\nprecision: |%ld|\nspecifier:
**|%d|\n", byte_to_binary(fmt.flag), fmt.width, fmt.precision, fmt.specifier);
**}
*/
