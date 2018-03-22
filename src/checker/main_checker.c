/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:17:19 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/22 10:52:12 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	check_if_sorted(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	if (b != NULL)
		ft_putstr("KO");
	else
	{
		while (a->next != NULL)
		{
			if (a->n > a->next->n)
			{
				ft_putstr("KO");
				return ;
			}
			a = a->next;
		}
		ft_putstr("OK");
	}
}

int	main(int ac, char **av)
{
	t_stacks *stacks;
	char	*operation;

	stacks = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	if (ac < 2)
		ft_putstr("usage: ./checker [-vc] [list of ints]\n");
	else
	{
		parser(stacks, av, ac);
		while (get_next_line(0, &operation) > 0)
			handle_ops(operation, stacks);
		check_if_sorted(stacks);
	}
	return (0);
}