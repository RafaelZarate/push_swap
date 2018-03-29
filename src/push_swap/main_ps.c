/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:56:35 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/28 06:29:22 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks *stacks;
	
	stacks = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	if (ac < 2)
		ft_putstr("usage: ./checker [-vc] [list of ints]\n");
	else
	{
		parser(stacks, av, ac);
		solver(stacks);
	}
	// print_stacks(stacks);
	return (0);
}