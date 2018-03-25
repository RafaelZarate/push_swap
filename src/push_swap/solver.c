/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 23:50:10 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/25 03:51:51 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	algorithm_1(t_stacks *stacks)
{	
	char	*a_op;
	char	*b_op;
	
	while (!check_if_sorted(stacks) || (stacks->min_a < stacks->max_b))
	{
		sort_a(stacks, &a_op);
		sort_b(stacks, &b_op);
		if (b_op != NULL)
		{
			if (ft_strcmp(a_op, "ra") == 0 && ft_strcmp(b_op, "rb") == 0)
				handle_ops("rr", stacks);
			else if (ft_strcmp(a_op, "sa") == 0 && ft_strcmp(b_op, "sb") == 0)
				handle_ops("ss", stacks);
			else if (ft_strcmp(a_op, "rra") == 0 && ft_strcmp(b_op, "rrb") == 0)
				handle_ops("rrr", stacks);
			else if (ft_strcmp(a_op, "pb") != 0)
				handle_ops(a_op, stacks);
			else if (ft_strcmp(a_op, "pb") == 0)
			{
				if (b_op)
					handle_ops(b_op, stacks);
				handle_ops(a_op, stacks);
			}
		}
		else if (ft_strcmp(a_op, "pb") != 0)
			handle_ops(a_op, stacks);
		else if (ft_strcmp(a_op, "pb") == 0)
		{
			if (b_op)
				handle_ops(b_op, stacks);
			handle_ops(a_op, stacks);
		}
		if (a_op != NULL)
			ft_strdel(&a_op);
		if (b_op != NULL)
			ft_strdel(&b_op);
	}
	return_to_a(stacks);
}

void	algorithm_2(t_stacks *stacks)
{
	
}

void	solver(t_stacks *stacks)
{
	ft_putstr("Initial stack: \n");
	print_stacks(stacks);

	if (stacks->length_a < 75)
		algorithm_1(stacks);
	else
		algorith_2(stacks);

	ft_putnbr(stacks->n_ops);
}
