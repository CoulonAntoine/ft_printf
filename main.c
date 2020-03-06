/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:28:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 12:23:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define INPUT "%000166.*u" ,-82,3240849627u
int		main(void)
{
	int	ft = 0;
	int	pf = 0;
	ft = ft_printf(INPUT);
	ft_putchar_fd('\n', 1);
	pf = printf(INPUT); 
	printf("\nft: %d\npf: %d\n", ft, pf);
}