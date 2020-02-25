/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:28:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/25 12:56:41 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define INPUT "%p", (void *)&test

int		main(void)
{
	int	ft = 0;
	int	pf = 0;
	int test = 42;
	
	ft = ft_printf(INPUT);
	ft_putchar_fd('\n', 1);
	pf = printf(INPUT);
	printf("\nft: %d\npf: %d\n", ft, pf);
}
