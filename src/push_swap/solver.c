/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 23:50:10 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/27 02:42:37 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_b(t_stacks *stacks, int	upper_limit, int lower_limit)
{
	get_current_position(stacks);
	if (stacks->a == NULL || stacks->min_a > upper_limit)
		return ;
	if (stacks->a_first <= upper_limit && stacks->a_first > lower_limit)
		handle_ops("pb", stacks);
	else
		handle_ops("ra", stacks);
	print_stacks(stacks);
	push_to_b(stacks, upper_limit, lower_limit);
}

void	return_partition_to_a(t_stacks *stacks, int	upper_limit, int lower_limit)
{
	t_sols	*solutions;
	t_stack	*a;
	t_stack	*b;
	int position;
	int i;

	i = 0;
	position = 0;
	while (position < stacks->partition_1_length && position >= stacks->partition_1_length)
	{
		
	}
}

void	algorithm_2(t_stacks *stacks)
{

	int	median_1;
	int	median_2;
	
	median_1 = get_median_1(stacks->a, stacks->length_a);
	median_2 = get_median_2(stacks->a, stacks->length_a);
	get_current_position(stacks);
	push_to_b(stacks, median_1, stacks->min_a - 1);
	push_to_b(stacks, median_2, median_1);
	push_to_b(stacks, stacks->max_a, median_2);
	// ft_putnbr(median_1);ft_putchar('\n');
	// ft_putnbr(median_2);ft_putchar('\n');
	// ft_putnbr(stacks->max_a);ft_putchar('\n');
	// print_stacks(stacks);
	return_partition_to_a(stacks, median_2, median_1);

}

void	solver(t_stacks *stacks)
{
	// ft_putstr("Initial stack: \n");
	// print_stacks(stacks);

	// if (stacks->length_a < 75)
	// 	algorithm_1(stacks);
	// else
	algorithm_2(stacks);

	// ft_putstr("Length A: ");ft_putnbr(stacks->length_a);ft_putchar('\n');
	// ft_putstr("Length B: ");ft_putnbr(stacks->length_b);ft_putchar('\n');
	ft_putstr("# of ops: ");ft_putnbr(stacks->n_ops);ft_putchar('\n');
}
