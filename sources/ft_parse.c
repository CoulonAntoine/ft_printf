/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:38:48 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/11 12:27:01 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

static void		ft_print_format(t_format fmt)
{
	printf("t_format\nflag: |%s|\nwidth: |%ld|\n precision: |%ld|\n specifier: |%d|\n", byte_to_binary(fmt.flag), fmt.width, fmt.precision, fmt.specifier);
}

t_uint64		ft_parse(const char *s, va_list *va)
{
	t_uint64	i;
	t_format	fmt;

	(void)va;
	i = 1;
	fmt.flag = 0;
	i += ft_parse_flags(&fmt, (char *)s + i);
	i += ft_parse_width(&fmt, (char *)s + i, va);
	i += ft_parse_precision(&fmt, (char *)s + i, va);
	i += ft_parse_specifier(&fmt, (char *)s + i);
	ft_print_format(fmt);
	return (i);
}
