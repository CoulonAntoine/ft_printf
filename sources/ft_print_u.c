/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 15:40:16 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_u(t_format *fmt, va_list *va, t_int32 *ret)
{
	(void)fmt;
	(void)va;
	(void)ret;
	ft_putchar_fd('u', 1);
}
