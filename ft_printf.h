/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:41:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/07 15:55:09 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define FLAG_NO BIT_0
# define FLAG_ZO BIT_1
# define FLAG_MI BIT_2

# define SPEC_C BIT_0
# define SPEC_S BIT_1
# define SPEC_P BIT_2
# define SPEC_D BIT_3
# define SPEC_I BIT_4

typedef struct	s_format
{
	t_uint8		flag;
	t_uint8		specifier;
	t_int64		width;
	t_int64		precision;
}				t_format;


int		ft_printf(const char *s, ...);

t_uint64	ft_parse(const char *s, va_list va)

#endif
