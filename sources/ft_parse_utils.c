/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:02:27 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/05 09:28:14 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_uint64	ft_parsing_atoi(char *s, t_uint64 *nbr)
{
	t_uint64	i;

	i = 0;
	*nbr = 0;
	while (s && s[i] && s[i] >= '0' && s[i] <= '9')
		*nbr = (*nbr * 10) + (s[i++] - '0');
	return (i);
}

t_uint64		ft_parse_flags(t_format *fmt, char *s)
{
	t_uint64	i;

	i = 0;
	while (s[i] && s[i] == '0')
	{
		fmt->flag |= FLAG_FILL_0;
		i++;
	}
	while (s[i] && s[i] == '-')
	{
		fmt->flag |= FLAG_LEFT;
		i++;
	}
	return (i);
}

t_uint64		ft_parse_width(t_format *fmt, char *s, va_list *va)
{
	t_uint64	nbr;
	t_uint64	i;

	if (s[0] == '*')
	{
		fmt->flag |= FLAG_WIDTH;
		fmt->width = va_arg(*va, int);
		return (1);
	}
	if ((i = ft_parsing_atoi(s, &nbr)))
	{
		if (nbr)
			fmt->flag += FLAG_WIDTH;
		fmt->width = nbr;
		return (i);
	}
	return (0);
}

t_uint64		ft_parse_precision(t_format *fmt, char *s, va_list *va)
{
	t_uint64	nbr;
	t_uint64	i;

	if (s[0] != '.')
		return (0);
	fmt->flag |= FLAG_PREC;
	if (s[1] == '*')
	{
		fmt->precision = va_arg(*va, int);
		return (2);
	}
	if (s && s[0] && (i = ft_parsing_atoi(s + 1, &nbr)))
	{
		fmt->precision = nbr;
		return (i + 1);
	}
	else
	{
		fmt->precision = 0;
		return (1);
	}
}

t_uint64		ft_parse_specifier(t_format *fmt, char *s)
{
	if (s[0] == 'c')
		fmt->specifier = CHAR;
	else if (s[0] == 's')
		fmt->specifier = STRING;
	else if (s[0] == 'p')
		fmt->specifier = POINTER;
	else if (s[0] == 'd' || s[0] == 'i')
		fmt->specifier = INTEGER;
	else if (s[0] == 'u')
		fmt->specifier = UINTEGER;
	else if (s[0] == 'x')
		fmt->specifier = HEX;
	else if (s[0] == 'X')
		fmt->specifier = CHEX;
	else if (s[0] == '%')
		fmt->specifier = PERCENT;
	else
		fmt->specifier = PERCENT;
	return (1);
}
