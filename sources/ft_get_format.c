/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:02:27 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/10 15:45:09 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64	ft_get_flags(t_format *fmt, char *s)
{
	if (s[0] == '0')
	{
		fmt->flag += FLAG_FILL_0;
		return (1);
	}
	if (s[0] == '-')
	{
		fmt->flag += FLAG_LEFT;
		return (1);
	}
	return (0);
}

t_uint64	ft_get_width(t_format *fmt, char *s)
{
	ft_atoi(s);
}

t_uint64	ft_get_precision(t_format *fmt, char *s)
{
	
}

t_uint64	ft_get_specifier(t_format *fmt, char *s)
{
	
}
