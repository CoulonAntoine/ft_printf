/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:13:50 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 11:04:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int32	ft_psize(t_uint64 nbr, char *b)
{
	t_int32		count;

	count = 0;
	while (nbr > 0)
	{
		nbr /= ft_strlen(b);
		count++;
	}
	if (!count)
		return (1);
	return (count);
}

static t_int32	ft_precpsize(t_format *fmt, t_uint64 nbr, char *b)
{
	t_int32		zero;

	if (!nbr && fmt->flag & FLAG_PREC && fmt->precision == 0)
		zero = 0;
	else
		zero = !nbr ? 1 : 0;
	return ((ft_psize(nbr, b) < fmt->precision ? fmt->precision :
	ft_psize(nbr, b)) - ft_psize(nbr, b) + zero);
}

static void		ft_printp_base(t_uint64 nbr, char *b, t_int32 *ret)
{
	if (nbr < ft_strlen(b))
		ft_putchar_pf(b[nbr], ret);
	else
	{
		ft_printp_base(nbr / ft_strlen(b), b, ret);
		ft_printp_base(nbr % ft_strlen(b), b, ret);
	}
}

t_int32			ft_plen(t_format *fmt, t_uint64 nbr, char *b)
{
	t_int32		nbrsize;
	t_int32		zeros;

	if (fmt->flag & FLAG_PREC)
	{
		if (fmt->precision < 0)
			fmt->precision = 1;
		zeros = !nbr && fmt->flag & FLAG_WIDTH ? 1 : 0;
		nbrsize = ft_psize(nbr, b);
		return (ft_precpsize(fmt, nbr, b) + nbrsize - zeros);
	}
	else
	{
		if (nbr)
			return (ft_psize(nbr, b));
		if (fmt->flag & FLAG_WIDTH && fmt->width > 0)
			return (ft_psize(nbr, b));
		return (0);
	}
}

void			ft_putp_pf(t_format *fmt, t_uint64 nbr, char *b, t_int32 *ret)
{
	if (fmt->flag & FLAG_PREC)
	{
		if (fmt->precision < 0)
			fmt->precision = 1;
		ft_printpad(1, ft_precpsize(fmt, nbr, b), ret);
		if (nbr)
		{
			ft_printp_base(nbr, b, ret);
		}
	}
	else
		ft_printp_base(nbr, b, ret);
}
