/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:28:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 17:19:44 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define INPUT "%s", "heyhey"

int		main(void)
{
	int	ft = 0;
	int	pf = 0;
	
	ft = ft_printf(INPUT);
	ft_putchar_fd('\n', 1);
	pf = printf(INPUT);
	printf("\nft: %d\npf: %d\n", ft, pf);
}
